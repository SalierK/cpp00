#include "PhoneBook.h"

std::string getValidPhoneNumber() {
    std::string phone_number;
    while (true) {
        std::cout << "Phone Number: ";
        std::getline(std::cin, phone_number);
        bool is_valid = true;
        for (char c : phone_number) {
            if (!std::isdigit(c)) {
                is_valid = false;
                break;
            }
        }
        if (is_valid) {
            break;
        } else {
            std::cout << "Invalid phone number. Please enter only digits." << std::endl;
        }
    }
    return phone_number;
}

std::string format_phonebook(const std::string& name) {
    if (name.length() > 10) {
        return name.substr(0, 9) + ".";
    } else {
        return name;
    }
}

int main() {
    PhoneBook my_phonebook;
    while (true) {
        std::string command;
        std::cout << "Komut Giriniz : ";
        std::getline(std::cin, command);
        if (command == "ADD") {
            std::string name, last_name, nick_name, ds;
            std::cout << "Name: ";
            std::getline(std::cin, name);
            std::cout << "Last Name: ";
            std::getline(std::cin, last_name);
            std::cout << "Nick Name: ";
            std::getline(std::cin, nick_name);
            std::string phone_number = getValidPhoneNumber();
            std::cout << "Darkest Secret: ";
            std::getline(std::cin, ds);
            Contacts new_contact(name, last_name, nick_name, phone_number, ds);
            my_phonebook.addContact(new_contact);
        } else if (command == "SEARCH") {
            std::cout << std::left << std::setw(14) << "Name" << "|"
                      << std::setw(14) << "Last Name" << "|"
                      << std::setw(14) << "Nick Name" << "|"
                      << std::setw(14) << "Phone Number" << "|"
                      << std::setw(14) << "Darkest Secret" << std::endl;
            std::cout << "-----------------------------------------------------------------" << std::endl;
            for (int i = 0; i < my_phonebook.contact_count; ++i) {
                Contacts contact = my_phonebook.getContact(i);
                std::cout << std::left << std::setw(14) << format_phonebook(contact.name) << "|"
                          << std::setw(14) << format_phonebook(contact.last_name) << "|"
                          << std::setw(14) << format_phonebook(contact.nick_name) << "|"
                          << std::setw(14) << format_phonebook(contact.phone_number) << "|"
                          << std::setw(14) << format_phonebook(contact.ds) << std::endl;
            }
        } else if (command == "EXIT") {
            break;
        }
    }
    return 0;
}