#include "Form.h"


Form::Form(std::string name, int grade_r_ss, int grade_r_ee) : name(name)
{
    if(grade_r_ss > 150)
        throw GradeTooLowException();
    else if(grade_r_ss < 1)
        throw GradeTooHighException();
    else
        this->gread_r_s = grade_r_ss;
    
    if(grade_r_ee > 150)
        throw GradeTooLowException();
    else if(grade_r_ee < 1)
        throw GradeTooHighException();
    else
        this->gread_r_e = grade_r_ee;

    this->is_signed = 0;
}

Form::~Form() {}

void Form::beSigned(Bureaucrat bureaucrat)
{
    if(bureaucrat.GetGrade() <= this->gread_r_s)
    {
        std::cout << bureaucrat.GetName() << " signed " << this->name << std::endl;
        signForm();
    }
    else
    {
        std::cout << bureaucrat.GetName() << " couldn't sign <" << this->name << " because his grade is lower than form." <<  std::endl;
    }
}

void Form::signForm()
{
    this->is_signed = 1;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const int Form::get_grade_requ_exec() const
{
    return gread_r_e;
}

const int Form::get_grade_requ_sign() const
{
    return gread_r_s;
}

const bool Form::get_issigned() const
{
    return is_signed;
}

const std::string Form::get_name() const
{
    return name;
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
    out <<"Form name is " <<form.get_name() << " and his grade to sign is " << form.get_grade_requ_sign() << " and his grade to exec " << form.get_grade_requ_exec() << " , last is signed status is " << form.get_issigned() << std::endl;
    return out;
}