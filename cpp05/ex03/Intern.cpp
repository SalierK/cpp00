#include "Intern.h"

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern &src)
{
    *this = src;
}
Intern &Intern::operator=(const Intern &src)
{
    *this = src;
}


AForm Intern::makeForm(std::string form_name, std::string target_f)
{

    if(form_name == "RobotomyRequestForm")
    {
        RobotomyRequestForm a(target_f);
        return a;
    }
    else if(form_name == "PresidentialPardonForm")
    {
        PresidentialPardonForm a(target_f);
        return a;
    }
    else if(form_name == "ShrubberyCreationForm")
    {
        PresidentialPardonForm a(target_f);
        return a;
    }

}