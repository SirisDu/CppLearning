// stonewt_type.cpp
// Stonewt class with operator overloading

#include <iostream>
#include "stonewt2.h"

int main()
{
    Stonewt wolfe(285.7);
    Stonewt taft(21, 8);

    wolfe.set_stn();
    std::cout << "Wolfe weight in stone format: ";
    std::cout << wolfe << std::endl;      // display in stone format
    wolfe.set_lbs_int();
    std::cout << "Wolfe weight in pounds integer format: ";
    std::cout << wolfe << std::endl;      // display in pounds integer format
    wolfe.set_lbs_double();
    std::cout << "Wolfe weight in pounds double format: ";
    std::cout << wolfe << std::endl;      // display in pounds double format

    std::cout << "Wolfe weight + Taft weight = ";
    std::cout << wolfe + taft << std::endl;
    std::cout << "Wolfe weight - Taft weight = ";
    std::cout << wolfe - taft << std::endl;
    std::cout << "Wolfe weight * 1.4 = ";
    std::cout << wolfe * 1.4 << std::endl;
}
