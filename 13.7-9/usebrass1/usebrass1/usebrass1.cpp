// usebrass1.cpp
// testing bank account classes

#include <iostream>
#include "brass.h"

int main()
{
    Brass Piggy("Porcelot Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
    Piggy.ViewAcct();
    std::cout << std::endl;
    Hoggy.ViewAcct();
    std::cout << std::endl;
    std::cout << "Depositing $1000 into the Hogg Account:" << std::endl;
    Hoggy.Deposit(1000.00);
    std::cout << "New balance: $" << Hoggy.Balance() << std::endl;
    std::cout << "Withdrawing $4200 from the Pigg Account:" << std::endl;
    Piggy.Withdraw(4200.00);
    std::cout << "Pigg account balance: $" << Piggy.Balance() << std::endl;
    std::cout << "Withdrawing $4200 from the Hogg Account:" << std::endl;
    Hoggy.Withdraw(4200.00);
    Hoggy.ViewAcct();
}
