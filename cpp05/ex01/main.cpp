#include "Bureaucrat.h"
#include "Form.h"
int main()
{
    Bureaucrat b("Kemal");
    Form f("Form",120,130);
    std::cout << b << std::endl;
    b.increment(130);
    std::cout << b << std::endl;
    std::cout << b << std::endl;
    f.beSigned(b);
    std::cout << f << std::endl;


}