// randwalk3.cpp
// N times random walk and display results

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector2.h"

int main()
{
    using VECTOR::Vector;

    srand(time(0));           // random seed generator

    double direction{};
    Vector step;
    Vector result(0.0, 0.0);
    double target{};
    double dstep{};

    std::cout << "Enter target distance (q to quit): ";
    while (std::cin >> target)                              // get target distance
    {
        std::cout << "Enter step length: ";
        if (!(std::cin >> dstep))                           // get step length
        {
            break;
        }

        int times{};
        std::cout << "Please enter times of random walk: ";
        if (!(std::cin >> times))
        {
            break;
        }
        unsigned long* steps = new unsigned long[times];    // get walk times

        for (int i = 0; i < times; i++)
        {
            steps[i] = 0;
            while (result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                ++(steps[i]);
            }
            result.reset();
        }                                                   // get steps results

        unsigned long max_steps{ steps[0] };
        unsigned long min_steps{ steps[0] };
        unsigned long sum{ steps[0] };
        unsigned long average_steps{};
        for (int i = 1; i < times; i++)
        {
            max_steps = max_steps >= steps[i] ? max_steps : steps[i];
            min_steps = min_steps <= steps[i] ? min_steps : steps[i];
            sum += steps[i];
        }
        average_steps = sum / times;                         // calculate max, min, and average values

        std::cout << "After " << times << " random walks:" << std::endl
            << "The slowest walk took " << max_steps << " steps." << std::endl
            << "The fastest walk took " << min_steps << " steps." << std::endl
            << "And the average steps = " << average_steps << ".\n";

        delete[] steps;
        std::cout << "Enter target distance (q to quit): ";
    }
    std::cout << "Bye!" << std::endl;
}
