// stacktem.cpp
// testing the template stack class

#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"

int main()
{
    Stack<std::string> st;                // create an empty stack
    char ch{};
    std::string po{};

    std::cout << "Please enter A to add a purchase order." << std::endl
        << "P to process a PO, or Q to quit." << std::endl;
    while (std::cin >> ch && toupper(ch) != 'Q')
    {
        while (std::cin.get() != '\n')
        {
            continue;
        }
        if (!isalpha(ch))
        {
            std::cout << '\a';
            continue;
        }
        switch (ch)
        {
        case 'A':
        case 'a':
            std::cout << "Enter a PO number to add: ";
            std::cin >> po;
            if (st.isfull())
            {
                std::cout << "stack already full" << std::endl;
            }
            else
            {
                st.push(po);
                break;
            }
        case 'P':
        case 'p':
            if (st.isempty())
            {
                std::cout << "stack already empty" << std::endl;
            }
            else
            {
                st.pop(po);
                std::cout << "PO #" << po << " popped" << std::endl;
                break;
            }
        }
        std::cout << "Please enter A to add a purchase order." << std::endl
            << "P to process a PO, or Q to quit." << std::endl;
    }
    std::cout << "Bye." << std::endl;
}
