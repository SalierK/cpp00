#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(std::string name)
{
    this->name = name;
    this->grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    this->name = src.name;
    this->grade = src.grade;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this != &src)
    {
        this->name = src.name;
        this->grade = src.grade;
    }
    return *this;
}

const int Bureaucrat::GetGrade() const
{

    return grade;
}

const std::string Bureaucrat::GetName() const
{
    return name;
}

void Bureaucrat::increment(int add_grade)
{
    if(grade - add_grade < 1)
        throw GradeTooLowException();
    else
        grade-=add_grade;
}

void Bureaucrat::decrement(int rem_grade)
{

    
    if(grade + rem_grade > 150)
        throw GradeTooHighException();
    else
        grade += rem_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}


std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    std::stringstream ss;
    ss << bureaucrat.GetGrade();
    out << bureaucrat.GetName() << ", bureaucrat grade " << ss.str();
    return out;
}