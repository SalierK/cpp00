#include "PhoneBook.h"
#include <iostream>
#include <iomanip> // setw ve left için gerekli
#include <string>

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
        std::cin >> command;
        if (command == "ADD") {
            std::string name, last_name, nick_name, ds;
            std::cout << "Ad: ";
            std::cin >> name;
            std::cout << "Soyad: ";
            std::cin >> last_name;
            std::cout << "Takma Ad: ";
            std::cin >> nick_name;
            std::cout << "Darkest Secret: ";
            std::cin >> ds;
            Contacts new_contact(name, last_name, nick_name, ds);
            my_phonebook.addContact(new_contact);
        } else if (command == "SEARCH") {
            std::cout << std::left << std::setw(12) << "Name" << "|"
                      << std::setw(12) << "Last Name" << "|"
                      << std::setw(12) << "Nick Name" << "|"
                      << std::setw(12) << "Darkest Secret" << std::endl;
            std::cout << "------------------------------------------------------------" << std::endl;
            for (int i = 0; i < my_phonebook.contact_count; ++i) {
                Contacts contact = my_phonebook.getContact(i);
                std::cout << std::left << std::setw(12) << format_phonebook(contact.name) << "|"
                          << std::setw(12) << format_phonebook(contact.last_name) << "|"
                          << std::setw(12) << format_phonebook(contact.nick_name) << "|"
                          << std::setw(12) << format_phonebook(contact.ds) << std::endl;
            }
        } else if (command == "EXIT") {
            break;
        }
    }
    return 0;
}