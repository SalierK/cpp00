#ifndef FORM_H
#define FORM_H
#include "Bureaucrat.h"
#include <iostream>
#include <string>

class Form : public std::exception
{
    private:
        const std::string name;
        bool is_signed;
        int gread_r_s;
        int gread_r_e;

    public:
        Form(std::string name, int grade_r_ss, int grade_r_ee);
        Form(const Form &src);
        ~Form();
        void beSigned(Bureaucrat bureaucrat);
        void signForm();
        Form &operator=(const Form &src);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        const int get_grade_requ_sign() const;
        const int get_grade_requ_exec() const;
        const bool get_issigned() const;
        const std::string get_name() const;
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif