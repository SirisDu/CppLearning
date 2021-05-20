// stonewt_compare.cpp
// Stonewt class with relational operators overloading

#include <iostream>
#include "stonewt3.h"

int main()
{
    Stonewt weights[6];

    weights[0] = 140;
    weights[1] = 154;
    weights[2] = 187;

    std::cout << "Please enter three weights in Lbs:" << std::endl;
    for (int i = 3; i < 6; i++)               // input 3 Stonewt objects
    {
        double lbs{};

        std::cout << "Weight #" << i + 1 << ": ";
        std::cin >> lbs;
        weights[i] = lbs;
    }

    int count{};
    int max_index{};
    int min_index{};
    if (weights[0] >= Stonewt(11, 0.0))       // compare weights[0] with 11 stones
    {
        ++count;
    }
    for (int i = 1; i < 6; i++)
    {
        if (weights[i] > weights[max_index])  // find max weight
        {
            max_index = i;
        }
        if (weights[i] < weights[min_index])  // find min weight
        {
            min_index = i;
        }
        if (weights[i] >= Stonewt(11, 0.0))   // compare weight with 11 stones
        {
            ++count;
        }
    }

    // display results
    std::cout << "The heaviest weight is #" << max_index + 1
        << ": " << weights[max_index] << "." << std::endl;
    std::cout << "And the lightest weight is #" << min_index + 1
        << ": " << weights[min_index] << "." << std::endl;
    std::cout << "And " << count
        << " of 6 weights are no less than 11 stones." << std::endl;
}
