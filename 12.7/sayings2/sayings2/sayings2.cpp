// sayings2.cpp
// using pointers to objects

#include <iostream>
#include <cstdlib>
#include <ctime>
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
    String sayings[ArSize];
    char temp[MaxLen]{};                          // temporary string storage
    int i{};
    for (i = 0; i < ArSize; i++)
    {
        std::cout << i + 1 << ": ";
        std::cin.get(temp, MaxLen);
        while (std::cin && std::cin.get() != '\n')
        {
            continue;
        }
        if (!std::cin || temp[0] == '\0')         // empty line?
        {
            break;                                // i not incremented
        }
        else
        {
            sayings[i] = temp;                    // overloaded assignment
        }
    }

    int total{ i };
    if (total > 0)
    {
        std::cout << "Here are your sayings:" << std::endl;
        for (i = 0; i < total; i++)
        {
            std::cout << sayings[i] << std::endl;
        }

        // use pointers to keep track of shortest, first strings
        String* shortest = &sayings[0];           // initialize to first object
        String* first = &sayings[0];
        for (i = 1; i < total; i++)
        {
            if (sayings[i].length() < shortest->length())
            {
                shortest = &sayings[i];
            }
            if (sayings[i] < *first)              // compare values
            {
                first = &sayings[i];              // assign address
            }
        }
        std::cout << "Shortest saying:" << std::endl << *shortest << std::endl;
        std::cout << "First alphabetically:" << std::endl << *first << std::endl;
        srand(time(0));
        int choice = rand() % total;              // pick index at random
        // use new to create, initialize new String object
        String* favorite = new String(sayings[choice]);
        std::cout << "My favorite saying:" << std::endl << *favorite << std::endl;
        delete favorite;
    }
    else
    {
        std::cout << "Not much to say, eh?" << std::endl;
    }
    std::cout << "Bye." << std::endl;
}
