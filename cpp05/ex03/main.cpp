#include "Intern.h"

int main()
{
    try{
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        // AForm* rrf2;
        // rrf2 = someRandomIntern.makeForm("FOO", "Bender");
        std::cout << rrf->get_name() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}