#include "Contacts.h"

Contacts::Contacts() : name(""), last_name(""), nick_name(""),phone_number(""), ds("") {
    
}

Contacts::Contacts(std::string name, std::string last_name, std::string nick_name,std::string phone_number, std::string ds)
    : name(name), last_name(last_name), nick_name(nick_name), ds(ds) , phone_number(phone_number){
}