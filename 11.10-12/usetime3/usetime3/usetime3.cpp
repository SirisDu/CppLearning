﻿// usetime3.cpp
// using the fourth draft of the Time class

#include <iostream>
#include "mytime3.h"

int main()
{
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    std::cout << "Aida and Tosca:" << std::endl;
    std::cout << aida << "; " << tosca << std::endl;
    temp = aida + tosca;              // operator +
    std::cout << "Aida + Tosca: " << temp << std::endl;
    temp = aida * 1.17;               // member operator*()
    std::cout << "Aida * 1.17: " << temp << std::endl;
    std::cout << "10.0 * Tosca: " << 10.0 * tosca << std::endl;
}
