#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>

class Bureaucrat : public std::exception {
    private:
        const std::string name;
        int               grade;
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &rhs);

        
        void    GradeTooHighException();
        void    GradeTooLowException();
        void    IncreaseGrade();
        void    DecreaseGrade();
};

#endif

