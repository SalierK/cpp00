#include "PhoneBook.h"

PhoneBook::PhoneBook() : contact_count(0) {
    for (int i = 0; i < 8; ++i) {
        my_contacts[i] = Contacts(); // Her bir elemanı varsayılan yapıcı ile başlat
    }
}

void PhoneBook::addContact(Contacts contact) {
    if (contact_count < 8) {
        my_contacts[contact_count] = contact;
        contact_count++;
    } else {
        for (int i = 1; i < 8; ++i) {
            my_contacts[i - 1] = my_contacts[i];
        }
        my_contacts[7] = contact;
    }
}

Contacts PhoneBook::getContact(int index) {
    if (index >= 0 && index < contact_count) {
        return my_contacts[index];
    }
    return Contacts(); // Return a default contact if index is out of bounds
}