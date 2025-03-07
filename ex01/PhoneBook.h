#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contacts.h"
#include <iomanip> 

class PhoneBook {
public:
    Contacts my_contacts[8];
    int contact_count;

    PhoneBook();
    void addContact(Contacts contact);
    Contacts getContact(int index);
};

#endif