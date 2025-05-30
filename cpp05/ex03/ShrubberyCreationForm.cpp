#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): target(target) , AForm("ShrubberyCreationForm", 145, 137, target)
{
	
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{

}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
    this->target = src.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
        this->target = src.target;
		AForm::operator=(src);
	}
	return *this;
}

const std::string get_name()
{
    return "TEST";
}

const std::string ShrubberyCreationForm::get_name() const
{
    return get_name();
}

void ShrubberyCreationForm::execute(const Bureaucrat bureaucrat) const
{
    if(bureaucrat.GetGrade() < get_grade_requ_exec() && get_issigned())
    {
        std::ofstream file(target + "_shrubbery");
        if (!file.is_open())
        {
            throw FileCreateError();
        }
    
        file << "       _-_\n";
        file << "    /~~   ~~\\\n";
        file << " /~~         ~~\\\n";
        file << "{               }\n";
        file << " \\  _-     -_  /\n";
        file << "   ~  \\\\ //  ~\n";
        file << "_- -   | | _- _\n";
        file << "  _ -  | |   -_\n";
        file << "      // \\\\\n";
    
        file.close();
    }
    else
        std::cout << "Grade or sign error" << std::endl;
}

