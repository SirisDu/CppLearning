// usett0.cpp
// using a base class

#include <iostream>
#include "tabtenn0.h"

int main()
{
    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);

    player1.Name();
    if (player1.HasTable())
    {
        std::cout << ": has a table." << std::endl;
    }
    else
    {
        std::cout << ": hasn't a table." << std::endl;
    }

    player2.Name();
    if (player2.HasTable())
    {
        std::cout << ": has a table." << std::endl;
    }
    else
    {
        std::cout << ": hasn't a table." << std::endl;
    }
}
