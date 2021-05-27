// usett1.cpp
// using base class and derived class

#include <iostream>
#include "tabtenn1.h"

int main()
{
    TableTennisPlayer player1("Tara", "Boomdea", false);
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
    rplayer1.Name();                  // derived object uses base method
    if (rplayer1.HasTable())
    {
        std::cout << ": has a table." << std::endl;
    }
    else
    {
        std::cout << ": hasn't a table." << std::endl;
    }
    player1.Name();                   // base object uses base method
    if (player1.HasTable())
    {
        std::cout << ": has a table." << std::endl;
    }
    else
    {
        std::cout << ": hasn't a table." << std::endl;
    }
    std::cout << "Name: ";
    rplayer1.Name();
    std::cout << ": Rating: " << rplayer1.Rating() << std::endl;
    // initialize RatePlayer using TableTennisPlayer object
    RatedPlayer rplayer2(1212, player1);
    std::cout << "Name: ";
    rplayer2.Name();
    std::cout << "; Rating: " << rplayer2.Rating() << std::endl;
}
