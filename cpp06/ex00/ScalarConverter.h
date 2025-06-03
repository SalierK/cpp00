#include <string.h>
#include <iostream>
#include <sstream>
#include <iomanip>

class ScalarConverter
{
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter &operator=(const ScalarConverter &src);

        static int Convert(std::string src);
};

int whats_that(std::string src);