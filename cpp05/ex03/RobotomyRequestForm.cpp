#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm(std::string target): target(target) , AForm("RobotomyRequestForm", 72, 45, target)
{
	
}
RobotomyRequestForm::~RobotomyRequestForm()
{

}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
    this->target = src.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
	{
        this->target = src.target;
		AForm::operator=(src);
	}
	return *this;
}

const std::string RobotomyRequestForm::get_name() const
{
    return get_name();
}

void RobotomyRequestForm::execute(const Bureaucrat bureaucrat) const
{
    if (bureaucrat.GetGrade() > get_grade_requ_exec() || !get_issigned())
    {
        std::cout << "Grade or sign error" << std::endl;
        return;
    }
    std::srand(std::time(0));
    std::cout << "* Drilling noises *" << std::endl;
    int i = std::rand();
    //std::cout << i << std::endl;
    if (i % 2 == 1)
    {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "The robotomy of " << target << " failed." << std::endl;
    }
}

