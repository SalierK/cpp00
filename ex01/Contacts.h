#ifndef CONTACTS_H
#define CONTACTS_H

#include <string>

class Contacts {
public:
    std::string name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string ds;

    Contacts();
    Contacts(std::string name, std::string last_name, std::string nick_name, std::string phone_number ,std::string ds);
};

#endif