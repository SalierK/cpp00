#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/select.h>

#define PORT 6667
#define MAX_CLIENTS 30
#define BUFFER_SIZE 512

struct Client {
    int fd;
    std::string nick;
    std::string user;
    std::string realname;
    bool registered = false;
    std::set<std::string> channels;
};

struct Channel {
    std::string name;
    std::set<int> clients;
};

std::map<int, Client> clients;
std::map<std::string, Channel> channels;

void send_msg(int fd, const std::string& msg) {
    std::string m = msg + "\r\n";
    send(fd, m.c_str(), m.size(), 0);
}

void broadcast(const std::string& channel, const std::string& msg, int except_fd = -1) {
    for (int fd : channels[channel].clients) {
        if (fd != except_fd)
            send_msg(fd, msg);
    }
}

void handle_nick(int fd, const std::string& nick) {
    for (const auto& [other_fd, c] : clients) {
        if (c.nick == nick) {
            send_msg(fd, ":server 433 * " + nick + " :Nickname is already in use");
            return;
        }
    }
    clients[fd].nick = nick;
    if (!clients[fd].user.empty() && !clients[fd].registered) {
        clients[fd].registered = true;
        send_msg(fd, ":server 001 " + nick + " :Welcome to the IRC server, " + nick);
    }
}

void handle_user(int fd, const std::string& user, const std::string& realname) {
    clients[fd].user = user;
    clients[fd].realname = realname;
    if (!clients[fd].nick.empty() && !clients[fd].registered) {
        clients[fd].registered = true;
        send_msg(fd, ":server 001 " + clients[fd].nick + " :Welcome to the IRC server, " + clients[fd].nick);
    }
}

void handle_join(int fd, const std::string& channel) {
    if (channel.empty() || channel[0] != '#') return;
    channels[channel].name = channel;
    channels[channel].clients.insert(fd);
    clients[fd].channels.insert(channel);
    send_msg(fd, ":" + clients[fd].nick + " JOIN " + channel);
    // Names reply
    std::string names;
    for (int cfd : channels[channel].clients)
        names += clients[cfd].nick + " ";
    send_msg(fd, ":server 353 " + clients[fd].nick + " = " + channel + " :" + names);
    send_msg(fd, ":server 366 " + clients[fd].nick + " " + channel + " :End of /NAMES list.");
}

void handle_part(int fd, const std::string& channel) {
    if (channels.count(channel) && channels[channel].clients.count(fd)) {
        channels[channel].clients.erase(fd);
        clients[fd].channels.erase(channel);
        send_msg(fd, ":" + clients[fd].nick + " PART " + channel);
        if (channels[channel].clients.empty())
            channels.erase(channel);
    }
}

void handle_privmsg(int fd, const std::string& target, const std::string& msg) {
    if (target.empty() || msg.empty()) return;
    if (target[0] == '#') {
        if (channels.count(target)) {
            for (int cfd : channels[target].clients) {
                if (cfd != fd)
                    send_msg(cfd, ":" + clients[fd].nick + " PRIVMSG " + target + " :" + msg);
            }
        }
    } else {
        for (const auto& [other_fd, c] : clients) {
            if (c.nick == target) {
                send_msg(other_fd, ":" + clients[fd].nick + " PRIVMSG " + target + " :" + msg);
                break;
            }
        }
    }
}

void handle_quit(int fd) {
    for (const std::string& channel : clients[fd].channels) {
        channels[channel].clients.erase(fd);
        if (channels[channel].clients.empty())
            channels.erase(channel);
    }
    send_msg(fd, "ERROR :Closing Link: " + clients[fd].nick);
    close(fd);
    clients.erase(fd);
}

void handle_ping(int fd, const std::string& token) {
    send_msg(fd, "PONG :" + token);
}

void parse_command(int fd, const std::string& line) {
    std::string cmd, rest;
    size_t pos = line.find(' ');
    if (pos != std::string::npos) {
        cmd = line.substr(0, pos);
        rest = line.substr(pos + 1);
    } else {
        cmd = line;
    }
    std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::toupper);

    if (cmd == "NICK") {
        handle_nick(fd, rest);
    } else if (cmd == "USER") {
        size_t pos2 = rest.find(':');
        std::string user = rest.substr(0, rest.find(' '));
        std::string realname = (pos2 != std::string::npos) ? rest.substr(pos2 + 1) : "";
        handle_user(fd, user, realname);
    } else if (cmd == "JOIN") {
        handle_join(fd, rest);
    } else if (cmd == "PART") {
        handle_part(fd, rest);
    } else if (cmd == "PRIVMSG") {
        size_t pos2 = rest.find(' ');
        std::string target = rest.substr(0, pos2);
        std::string msg = rest.substr(pos2 + 2); // skip " :"
        handle_privmsg(fd, target, msg);
    } else if (cmd == "QUIT") {
        handle_quit(fd);
    } else if (cmd == "PING") {
        handle_ping(fd, rest);
    }
}

int main() {
    int server_fd, new_socket, max_sd, activity, valread, sd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE];

    fd_set readfds;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    std::cout << "IRC server started on port " << PORT << std::endl;

    while (true) {
        FD_ZERO(&readfds);
        FD_SET(server_fd, &readfds);
        max_sd = server_fd;

        for (const auto& [fd, c] : clients) {
            FD_SET(fd, &readfds);
            if (fd > max_sd) max_sd = fd;
        }

        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if (FD_ISSET(server_fd, &readfds)) {
            new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
            clients[new_socket] = Client{new_socket};
            send_msg(new_socket, ":server NOTICE AUTH :Welcome! Please register with NICK and USER.");
        }

        std::vector<int> disconnected;
        for (auto& [fd, c] : clients) {
            if (FD_ISSET(fd, &readfds)) {
                memset(buffer, 0, BUFFER_SIZE);
                valread = recv(fd, buffer, BUFFER_SIZE - 1, 0);
                if (valread <= 0) {
                    disconnected.push_back(fd);
                } else {
                    std::string data(buffer);
                    size_t pos;
                    while ((pos = data.find("\r\n")) != std::string::npos) {
                        std::string line = data.substr(0, pos);
                        parse_command(fd, line);
                        data.erase(0, pos + 2);
                    }
                }
            }
        }
        for (int fd : disconnected) {
            handle_quit(fd);
        }
    }
    return 0;
}