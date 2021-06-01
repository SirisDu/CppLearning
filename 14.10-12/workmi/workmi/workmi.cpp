// workmi.cpp
// multiple inheritance

#include <iostream>
#include <cstring>
#include "workermi.h"

const int SIZE{ 5 };

int main()
{
    Worker* lolas[SIZE];
    
    int ct{};
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice{};
        std::cout << "Enter the employee category:" << std::endl
            << "w: waiter  s: singer  "
            "t: singing waiter  q: quit" << std::endl;
        std::cin >> choice;
        while (strchr("wstq", choice) == nullptr)
        {
            std::cout << "Please enter a w, s, t, or q: ";
            std::cin >> choice;
        }
        if (choice == 'q')
        {
            break;
        }
        switch (choice)
        {
        case 'w':
            lolas[ct] = new Waiter;
            break;
        case 's':
            lolas[ct] = new Singer;
            break;
        case 't':
            lolas[ct] = new SingerWaiter;
            break;
        }
        std::cin.get();
        lolas[ct]->Set();
    }

    std::cout << std::endl << "Here is your staff:" << std::endl;
    for (int i = 0; i < ct; i++)
    {
        std::cout << std::endl;
        lolas[i]->Show();
    }
    for (int i = 0; i < ct; i++)
    {
        delete lolas[i];
    }
    std::cout << "Bye." << std::endl;
}
