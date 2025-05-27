#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include <iostream>
#include <string>
#include <sstream>

class Bureaucrat : public std::exception
{
    private:
        std::string name;
        int grade;

    public:
        Bureaucrat(std::string name);
        virtual ~Bureaucrat() throw();
        Bureaucrat(const Bureaucrat &src);

        Bureaucrat &operator=(const Bureaucrat &src);

        const int GetGrade() const;
        const std::string GetName() const;
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
        void increment(int add_grade);
        void decrement(int rem_grade);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
