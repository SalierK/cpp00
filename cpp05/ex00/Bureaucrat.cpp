#include "Bureaucrat.h"



void  Bureaucrat::GradeTooHighException() {
    
}

void  Bureaucrat::GradeTooLowException() {

}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    *this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    if(this != &rhs)
    {
        this->grade = rhs.grade;
        this->name = rhs.name;
    }
    return *this;
}

Bureaucrat::Bureaucrat()
{

}
Bureaucrat::~Bureaucrat()
{

}

