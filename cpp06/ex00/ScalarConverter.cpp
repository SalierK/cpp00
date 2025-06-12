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
        float tem_float = std::stof(src);
        if (tem_float >= 0 && tem_float <= 127)
        {
            if (tem_float >= 32 && tem_float <= 126)
                std::cout << "char : '" << static_cast<char>(tem_float) << "'" << std::endl;
            else
                std::cout << "char : impossible" << std::endl;
        }
        else
            std::cout << "char : impossible" << std::endl;

        std::cout << "int : " << static_cast<int>(tem_float) << std::endl;
        std::cout << "float : " << std::fixed << tem_float << "f" << std::endl;
        std::cout << "double : " << static_cast<double>(tem_float) << std::endl;
    }
    else if(whats_that(src) == 2)
    {
        double tem_double = std::stod(src);
        if (tem_double >= 0 && tem_double <= 127)
        {
            if (tem_double >= 32 && tem_double <= 126)
                std::cout << "char : '" << static_cast<char>(tem_double) << "'" << std::endl;
            else
                std::cout << "char : impossible" << std::endl;
        }
        else
            std::cout << "char : impossible" << std::endl;

        std::cout << "int : " << static_cast<int>(tem_double) << std::endl;
        std::cout << "float : " << std::fixed << static_cast<float>(tem_double) << "f" << std::endl;
        std::cout << "double : " << tem_double << std::endl;
    }
    else if(whats_that(src) == 3)
    {
        int tem_int = std::stoi(src);
        if (tem_int >= 0 && tem_int <= 127)
        {
            if (tem_int >= 32 && tem_int <= 126)
                std::cout << "char : '" << static_cast<char>(tem_int) << "'" << std::endl;
            else
                std::cout << "char : impossible" << std::endl;
        }
        else
            std::cout << "char : impossible" << std::endl;

        std::cout << "int : " << tem_int << std::endl;
        std::cout << "float : " << static_cast<float>(tem_int) << "f" << std::endl;
        std::cout << "double : " << static_cast<double>(tem_int) << std::endl;
    }
    else
        return -1; 
    return 0;
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