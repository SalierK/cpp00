#include "AForm.h"


AForm::AForm(std::string name, int grade_r_ss, int grade_r_ee) : name(name)
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
AForm::AForm(const AForm &src)
    : name(src.name), is_signed(src.is_signed), gread_r_s(src.gread_r_s), gread_r_e(src.gread_r_e)
{
}

AForm &AForm::operator=(const AForm &src)
{
    if (this != &src)
    {
        // name is const, so don't assign it
        is_signed = src.is_signed;
        gread_r_s = src.gread_r_s;
        gread_r_e = src.gread_r_e;
    }
    return *this;
}

AForm::~AForm() {}

void AForm::beSigned(Bureaucrat bureaucrat)
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

void AForm::signForm()
{
    this->is_signed = 1;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char *AForm::FileCreateError::what() const throw()
{
    return "Failed to create the file" ;
}

const int AForm::get_grade_requ_exec() const
{
    return gread_r_e;
}

const int AForm::get_grade_requ_sign() const
{
    return gread_r_s;
}

const bool AForm::get_issigned() const
{
    return is_signed;
}

const std::string AForm::get_name() const
{
    return name;
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
    out <<"Form name is " <<form.get_name() << " and his grade to sign is " << form.get_grade_requ_sign() << " and his grade to exec " << form.get_grade_requ_exec() << " , last is signed status is " << form.get_issigned() << std::endl;
    return out;
}