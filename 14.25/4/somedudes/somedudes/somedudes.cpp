// somedudes.cpp
// multiple inheritance

#include <iostream>
#include <cstring>
#include "dudes.h"

const int SIZE{ 5 };

int main()
{
    Person* lolas[SIZE];

    int ct{};
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice{};
        std::cout << "Enter the person category:" << std::endl
            << "n: person  g: gunslinger  "
            "p: pokerplayer  b: baddude  "
            "q: quit" << std::endl;
        std::cin >> choice;
        while (strchr("ngpbq", choice) == nullptr)
        {
            std::cout << "Please enter a n, g, p, b, or q: ";
            std::cin >> choice;
        }
        if (choice == 'q')
        {
            break;
        }
        switch (choice)
        {
        case 'n':
            lolas[ct] = new Person;
            break;
        case 'g':
            lolas[ct] = new Gunslinger;
            break;
        case 'p':
            lolas[ct] = new PokerPlayer;
            break;
        case 'b':
            lolas[ct] = new BadDude;
        }
        std::cin.get();
        lolas[ct]->Set();
    }

    std::cout << std::endl << "Here are your dudes:" << std::endl;
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
