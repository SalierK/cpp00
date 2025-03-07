#include "Contacts.h"

// Varsayılan yapıcı tanımı
Contacts::Contacts() : name(""), last_name(""), nick_name(""), phone_number("") {
    
}

Contacts::Contacts(std::string name, std::string last_name, std::string nick_name, std::string phone_number)
    : name(name), last_name(last_name), nick_name(nick_name), phone_number(phone_number) {

    }