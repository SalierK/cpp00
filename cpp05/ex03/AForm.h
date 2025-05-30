#ifndef FORM_H
#define FORM_H
#include "Bureaucrat.h"
#include <iostream>
#include <string>
#include <fstream>

class AForm : public std::exception
{
    private:
        const std::string name;
        const std::string target;
        bool is_signed;
        const int gread_r_s;
        const int gread_r_e;

    public:
        AForm(std::string name, int grade_r_ss, int grade_r_ee, std::string target);
        AForm(const AForm &src);
        ~AForm();
        void beSigned(Bureaucrat bureaucrat);
        void signForm();
        AForm &operator=(const AForm &src);

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
        
        class FileCreateError : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        const int get_grade_requ_sign() const;
        const int get_grade_requ_exec() const;
        const bool get_issigned() const;
        const std::string get_target() const;
        virtual const std::string get_name() const = 0;
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif