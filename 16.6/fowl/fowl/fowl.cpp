// fowl.cpp
// auto_ptr a poor choice

#include <iostream>
#include <string>
#include <memory>

int main()
{
    std::shared_ptr<std::string> films[5]{
        std::shared_ptr<std::string>(new std::string("Fowl Balls")),
        std::shared_ptr<std::string>(new std::string("Duck Walks")),
        std::shared_ptr<std::string>(new std::string("Chicken Runs")),
        std::shared_ptr<std::string>(new std::string("Turkey Errors")),
        std::shared_ptr<std::string>(new std::string("Goose Eggs"))
    };
    std::shared_ptr<std::string> pwin;
    pwin = films[2];           // films[2] loses ownership

    std::cout << "The nominees for best avian baseball film are" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << *films[i] << std::endl;
    }
    std::cout << "The winner is " << *pwin << "!" << std::endl;
}
