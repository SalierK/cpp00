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


AForm* Intern::makeForm(std::string form_name, std::string target_f)
{

    if(form_name == "RobotomyRequestForm")
    {
        
        return new RobotomyRequestForm(target_f);
    }
    else if(form_name == "PresidentialPardonForm")
    {
        
        return new PresidentialPardonForm(target_f);
    }
    else if(form_name == "ShrubberyCreationForm")
    {
        
        return new ShrubberyCreationForm(target_f);
    }

}