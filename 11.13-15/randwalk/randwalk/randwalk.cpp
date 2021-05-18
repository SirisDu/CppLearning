// randwalk.cpp
// using the Vector class

#include <iostream>
#include <cstdlib>            // rand(), srand(), prototypes
#include <ctime>              // time() prototype
#include "vector.h"

int main()
{
    using VECTOR::Vector;

    srand(time(0));           // seed random-number generator

    double direction{};
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps{ 0 };
    double target{};
    double dstep{};

    std::cout << "Enter target distance (q to quit): ";
    while (std::cin >> target)
    {
        std::cout << "Enter step length: ";
        if (!(std::cin >> dstep))
        {
            break;
        }
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            ++steps;
        }
        std::cout << "After " << steps << " steps, the subject "
            "has the following location:" << std::endl;
        std::cout << result << std::endl;
        result.polar_mode();
        std::cout << " or" << std::endl << result << std::endl;
        std::cout << "Average outward distance per step = "
            << result.magval() / steps << std::endl;

        steps = 0;
        result.reset();
        std::cout << "Enter target distance (q to quit): ";
    }
    std::cout << "Bye!" << std::endl;
}
