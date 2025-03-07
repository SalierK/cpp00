#include "PhoneBook.h"
#include <iostream>
#include <string>

int main() {
    PhoneBook my_phonebook;
    while (true) {
        std::string command;
        std::cout << "Komut Giriniz : ";
        std::cin >> command;
        if (command == "ADD") {
            std::string name, last_name, nick_name, phone_number;
            std::cout << "Ad: ";
            std::cin >> name;
            std::cout << "Soyad: ";
            std::cin >> last_name;
            std::cout << "Takma Ad: ";
            std::cin >> nick_name;
            std::cout << "Darkest Secret: ";
            std::cin >> phone_number;
            Contacts new_contact(name, last_name, nick_name, phone_number);
            my_phonebook.addContact(new_contact);
        } else if (command == "SEARCH") {
            for (int i = 0; i < my_phonebook.contact_count; ++i) {
                Contacts contact = my_phonebook.getContact(i);
                std::cout << "Kayıt " << i + 1 << ": " << contact.name << " " << contact.last_name << " (" << contact.nick_name << ") - " << contact.phone_number << std::endl;
            }
        } else if (command == "EXIT") {
            break;
        }
    }
    return 0;
}