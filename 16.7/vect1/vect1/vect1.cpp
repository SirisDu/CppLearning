// vect1.cpp
// introducing the vector template

#include <iostream>
#include <string>
#include <vector>

const int NUM{ 5 };

int main()
{
    std::vector<int> ratings(NUM);
    std::vector<std::string> titles(NUM);

    std::cout << "You will do exactly as told. You will enter" << std::endl
        << NUM << " book titles and your ratings (0-10)." << std::endl;
    for (int i = 0; i < NUM; i++)
    {
        std::cout << "Enter title #" << i + 1 << ": ";
        std::getline(std::cin, titles[i]);
        std::cout << "Enter your rating (0-10): ";
        std::cin >> ratings[i];
        std::cin.get();
    }
    std::cout << "Thank you. You entered the following:" << std::endl
        << "Rating\tBook" << std::endl;
    for (int i = 0; i < NUM; i++)
    {
        std::cout << ratings[i] << "\t" << titles[i] << std::endl;
    }
}
