// str2.cpp
// capacity() and reverse()

#include <iostream>
#include <string>

int main()
{
    std::string empty;
    std::string small = "bit";
    std::string larger = "Elephants are a girl's best friend";

    std::cout << "Sizes:" << std::endl;
    std::cout << "\tempty: " << empty.size() << std::endl;
    std::cout << "\tsmall: " << small.size() << std::endl;
    std::cout << "\tlarger: " << larger.size() << std::endl;
    std::cout << "Capacities:" << std::endl;
    std::cout << "\tempty: " << empty.capacity() << std::endl;
    std::cout << "\tsmall: " << small.capacity() << std::endl;
    std::cout << "\tlarger: " << larger.capacity() << std::endl;
    empty.reserve(50);
    std::cout << "Capacity after empty.reserve(50): " <<
        empty.capacity() << std::endl;
}
