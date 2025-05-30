#ifndef INTERN_H
#define INTERN_H

#include "Bureaucrat.h"
#include "AForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "ShrubberyCreationForm.h"
class Intern
{
    private:
        
    public:
        Intern();
        ~Intern();
        Intern(const Intern &src);
        Intern &operator=(const Intern &src);
        AForm makeForm(std::string form_name, std::string target_f);
        class 
};


#endif

