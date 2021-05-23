// sayings.cpp
// using expended String class

#include <iostream>
#include "string1.h"

const int ArSize{ 10 };
const int MaxLen{ 81 };

int main()
{
    String name;

    std::cout << "Hi, what's your name?" << std::endl << ">> ";
    std::cin >> name;

    std::cout << name << ", please enter up to " << ArSize
        << " short sayings <empty line to quit>:" << std::endl;
    String sayings[ArSize];                     // array of objects
    char temp[MaxLen]{};                        // temporary string storage

    int i{};
    for (i = 0; i < ArSize; i++)
    {
        std::cout << i + 1 << ": ";
        std::cin.get(temp, MaxLen);
        while (std::cin && std::cin.get() != '\n')
        {
            continue;
        }
        if (!std::cin || temp[0] == '\0')       // empty line?
        {
            break;                              // i not incremented
        }
        else
        {
            sayings[i] = temp;                  // overloaded assignment
        }
    }

    int total{ i };                             // total # of lines read
    if (total > 0)
    {
        std::cout << "Here are your sayings:" << std::endl;
        for (int i = 0; i < total; i++)
        {
            std::cout << sayings[i][0] << ": " << sayings[i] << std::endl;
        }

        int shortest{};
        int first{};
        for (int i = 1; i < total; i++)
        {
            if (sayings[i].length() < sayings[shortest].length())
            {
                shortest = i;
            }
            if (sayings[i] < sayings[first])
            {
                first = i;
            }
        }
        std::cout << "Shortest saying:" << std::endl << sayings[shortest] << std::endl;
        std::cout << "First alphabetically:" << std::endl << sayings[first] << std::endl;
        std::cout << "This program used " << String::HowMany()
            << " String objects. Bye." << std::endl;
    }
    else
    {
        std::cout << "No input! Bye." << std::endl;
    }
}
