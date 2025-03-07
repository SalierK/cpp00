#include "Contacts.h"

Contacts::Contacts() : name(""), last_name(""), nick_name(""), ds("") {
    
}

Contacts::Contacts(std::string name, std::string last_name, std::string nick_name, std::string ds)
    : name(name), last_name(last_name), nick_name(nick_name), ds(ds) {
}