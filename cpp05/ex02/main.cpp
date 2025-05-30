#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
int main()
{
    Bureaucrat b("Kemal");
    std::cout << b << std::endl;
    b.increment(130);
    ShrubberyCreationForm s("Home");
    RobotomyRequestForm r("Robo");
    r.beSigned(b);
    std::cout << b << std::endl;
    std::cout << b << std::endl;
    s.execute(b);
    r.execute(b);
    std::cout << b << std::endl;
}