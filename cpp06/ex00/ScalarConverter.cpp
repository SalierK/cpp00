#include "ScalarConverter.h"

int ScalarConverter::Convert(std::string src)
{
    std::cout << whats_that(src) << std::endl;
    std::cout << std::setprecision(1);
    if(whats_that(src) == 0)
    {
        char tem_char = src[0];
        std::cout << "char : " << static_cast<char>(tem_char)  << std::endl;
        std::cout << "int : " << static_cast<int>(tem_char)  << std::endl;
        std::cout << "float : " << std::fixed  << static_cast<float>(tem_char) << "f" << std::endl;
        std::cout << "double : " << static_cast<double>(tem_char)  << std::endl;
    }
    else if(whats_that(src) == 1)
    {
        char tem_char = src[0];

        std::cout << "char : " << static_cast<char>(tem_char)  << std::endl;
        std::cout << "int : " << static_cast<int>(tem_char)  << std::endl;
        std::cout << "float : " << std::fixed  << static_cast<float>(tem_char) << "f" << std::endl;
        std::cout << "double : " << static_cast<double>(tem_char)  << std::endl;
    }
    return 1;  
}

int whats_that(std::string src)
{

    if (src.length() == 1)
        return 0; 

    if (src.back() == 'f') {
        std::string num = src.substr(0, src.length() - 1);
        std::istringstream iss(num);
        float f;
        if (iss >> f && iss.eof())
            return 1; 
    }

    std::istringstream iss(src);
    double d;
    if (iss >> d && iss.eof())
        return 2;


    std::istringstream iss2(src);
    int i;
    if (iss2 >> i && iss2.eof())
        return 3; 

    return 4;
}