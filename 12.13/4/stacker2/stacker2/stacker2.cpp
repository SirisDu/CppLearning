// stacker2.cpp
// dynamic stack

#include <iostream>
#include <cctype>
#include "stack.h"

void stack_io(Stack& st);

int main()
{
    int size{};
    std::cout << "Please enter the size of a stack: ";
    std::cin >> size;
    while (std::cin.get() != '\n')
    {
        continue;
    }

    Stack st(size);                     // create an empty stack
    stack_io(st);

    std::cout << "Now copying this stack to another stack..." << std::endl;
    Stack st2(st);
    stack_io(st2);

    std::cout << "Now assigning this stack to another stack..." << std::endl;
    Stack st3 = st2;
    stack_io(st3);

    std::cout << "Now back to the original stack..." << std::endl;
    stack_io(st);

    std::cout << "Bye" << std::endl;
}

// io operation for a stack
void stack_io(Stack& st) {
    char ch{};
    Item po{};
    std::cout << "Please enter A to add a purchase order," << std::endl
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
            }
            break;
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
            }
            break;
        }
        std::cout << "Please enter A to add a purchase order," << std::endl
            << "P to process a PO, or Q to quit." << std::endl;
    }
}
