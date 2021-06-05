// useemp.cpp
// using the abstr_emp classes

#include <iostream>
#include "emp.h"

int main()
{
    employee em("Trip", "Harris", "Thumper");
    std::cout << em << std::endl;
    em.ShowAll();
    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    std::cout << ma << std::endl;
    ma.ShowAll();

    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    std::cout << fi << std::endl;
    fi.ShowAll();
    highfink hf(ma, "Curly Kew");       // recruitment
    hf.ShowAll();
    std::cout << "Press a key for next phase:" << std::endl;
    std::cin.get();
    highfink hf2;
    hf2.SetAll();

    std::cout << "Using an abstr_emp* pointer:" << std::endl;
    abstr_emp* tri[4] { &em, &fi, &hf, &hf2 };
    for (int i = 0; i < 4; i++)
    {
        tri[i]->ShowAll();
    }
}
