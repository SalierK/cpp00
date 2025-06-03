#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm(std::string target): target(target) , AForm("PresidentialPardonForm", 25, 5, target)
{
	
}
PresidentialPardonForm::~PresidentialPardonForm()
{

}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{
    this->target = src.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
	{
        this->target = src.target;
		AForm::operator=(src);
	}
	return *this;
}

const std::string PresidentialPardonForm::get_name() const
{
    return AForm::get_name();
}

void PresidentialPardonForm::execute(const Bureaucrat bureaucrat) const
{
    if (bureaucrat.GetGrade() > get_grade_requ_exec() || !get_issigned())
    {
        std::cout << "Grade or sign error" << std::endl;
        return;
    }
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}