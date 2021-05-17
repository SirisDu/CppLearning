// walker.cpp
// using the Vector class and output result into a file

#include <iostream>
#include <fstream>
#include <cstdlib>            // rand(), srand(), prototypes
#include <ctime>              // time() prototype
#include "vector.h"

int main()
{
    using VECTOR::Vector;

    srand(time(0));           // seed random-number generator

    std::ofstream outFile;    // create object for output
    outFile.open("walk results.txt");

    double direction{};
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps{ 0 };
    double target{};
    double dstep{};
    int count{};

    std::cout << "Enter target distance (q to quit): ";
    while (std::cin >> target)
    {
        std::cout << "Enter step length: ";
        if (!(std::cin >> dstep))
        {
            break;
        }
        outFile << "Walk #" << count << ":" << std::endl;
        outFile << "Target Distance: " << target
            << ", Step Size: " << dstep << std::endl;

        outFile << "0: (x, y) = (0, 0)" << std::endl;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            ++steps;
            outFile << steps << ": " << result << std::endl;
        }
        // console
        std::cout << "After " << steps << " steps, the subject "
            "has the following location:" << std::endl;
        std::cout << result << std::endl;
        result.polar_mode();
        std::cout << " or" << std::endl << result << std::endl;
        std::cout << "Average outward distance per step = "
            << result.magval() / steps << std::endl;
        std::cout << std::endl;
        // out file
        result.rect_mode();
        outFile << "After " << steps << " steps, the subject "
            "has the following location:" << std::endl;
        outFile << result << std::endl;
        result.polar_mode();
        outFile << " or" << std::endl << result << std::endl;
        outFile << "Average outward distance per step = "
            << result.magval() / steps << std::endl;
        outFile << std::endl;

        steps = 0;
        result.reset();
        ++count;
        std::cout << "Enter target distance (q to quit): ";
    }
    std::cout << "Bye!" << std::endl;

    outFile.close();
}
