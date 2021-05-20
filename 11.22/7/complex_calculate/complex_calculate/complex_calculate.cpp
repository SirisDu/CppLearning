// complex_calculate.cpp
// using complex class

#include <iostream>
#include "complex0.h"          // to avoid confusion with complex.h

int main()
{
    complex a(3.0, 4.0);       // initialize to (3,4i)
    complex c;

    std::cout << "Enter a complex number (q to quit):\n";
    while (std::cin >> c)
    {
        std::cout << "c is " << c << std::endl;
        std::cout << "complex conjugate is " << ~c << std::endl;
        std::cout << "a is " << a << std::endl;
        std::cout << "a + c is " << a + c << std::endl;
        std::cout << "a - c is " << a - c << std::endl;
        std::cout << "a * c is " << a * c << std::endl;
        std::cout << "2 * c is " << 2 * c << std::endl;
        std::cout << "Enter a complex number (q to quit):" << std::endl;
    }
    std::cout << "Done!" << std::endl;
}
