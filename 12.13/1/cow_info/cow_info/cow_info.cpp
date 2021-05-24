// cow_info.cpp
// store and display cow information

#include <iostream>
#include "cow.h"

int main()
{
    {
        Cow cow1;                            // use default constructor

        Cow cow2("cow2", "eating", 100);     // use custom constructor
        std::cout << "Using custom constructor, cow2:" << std::endl;
        cow2.ShowCow();

        cow1 = cow2;                         // use copy and assignment
        std::cout << "Using copy and assignment, cow1:" << std::endl;
        cow1.ShowCow();
    }
    std::cout << "Done!" << std::endl;
}
