#include "Intern.h"

std::string const _formNames[3] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
};

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
    return *this;
}


AForm* Intern::makeForm(std::string form_name, std::string target_f)
{
    for (size_t i = 0; i < 3; i++)
    {
        if (form_name == _formNames[i])
        {
            switch (i)
            {
                case 0:
                {
                    std::cout << "Intern creates " << form_name << std::endl;
                    return new ShrubberyCreationForm(target_f);
                }
                case 1:
                {
                    std::cout << "Intern creates " << form_name << std::endl;
                    return new RobotomyRequestForm(target_f);
                }
                case 2:
                {
                    std::cout << "Intern creates " << form_name << std::endl;
                    return new PresidentialPardonForm(target_f);
                }
                default:
                    throw ExplicitError();
            }
        }
    }
    throw ExplicitError();
}
const char* Intern::ExplicitError::what() const throw()
{
    return "Explicit Error";
}