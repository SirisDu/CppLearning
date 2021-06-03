// wine.cpp
// using Wine class with containment

#include <iostream>
#include "winec.h"

int main()
{
    std::cout << "Enter name of wine: ";
    char lab[50]{};
    std::cin.getline(lab, 50);
    std::cout << "Enter number of years: ";
    int yrs{};
    std::cin >> yrs;

    Wine holding(lab, yrs);     // store label, year, give arrays yrs elements
    holding.GetBottles();       // solicit input for year, bottle count
    holding.Show();             // display object contents

    const int YRS{ 3 };
    int y[YRS]{ 1993, 1995, 1998 };
    int b[YRS]{ 48, 60, 72 };
    // create new object, initialize using data in arrays y and b
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    std::cout << "Total bottles for " << more.Label()   // use Label() method
        << ": " << more.sum() << std::endl;             // use sum() method
    std::cout << "Bye." << std::endl;
}
