// pe12_2.cpp
// using string2

#include <iostream>
#include "string2.h"

int main()
{
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name: ";
    String s3;
    std::cout << s2;                 // overloaded << operator
    std::cin >> s3;                  // overloaded >> operator
    s2 = "My name is " + s3;         // overloaded =, + operators
    std::cout << s2 << "." << std::endl;
    s2 = s2 + s1;
    s2.stringup();                   // converts string to uppercase
    std::cout << "The string" << std::endl
        << s2 << std::endl
        << "contains " << s2.has('A') << " 'A' characters in it."
        << std::endl;
    s1 = "red";                      // String(const char*)
    String rgb[3] = { String(s1), String("green"), String("blue") };
    std::cout << "Enter the name of a primary color for mixing light: ";
    String ans;
    bool success{ false };
    while (std::cin >> ans)
    {
        ans.stringlow();             // converts string to lowercase
        for (int i = 0; i < 3; i++)
        {
            if (ans == rgb[i])       // overloaded == operator
            {
                std::cout << "That's right!" << std::endl;
                success = true;
                break;
            }
        }
        if (success)
        {
            break;
        }
        else
        {
            std::cout << "Try again!" << std::endl;
        }
    }
    std::cout << "Bye." << std::endl;
}
