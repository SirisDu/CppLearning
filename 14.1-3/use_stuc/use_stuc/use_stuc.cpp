// use_stuc.cpp
// using a composite class

#include <iostream>
#include "studentc.h"

void set(Student& sa, int n);

const int pupils{ 3 };
const int quizzes{ 5 };

int main()
{
    Student ada[pupils] = 
    { Student(quizzes), Student(quizzes), Student(quizzes) };

    int i{};
    for (i = 0; i < pupils; i++)
    {
        set(ada[i], quizzes);
    }
    std::cout << std::endl << "Student List:" << std::endl;
    for (i = 0; i < pupils; i++)
    {
        std::cout << std::endl << ada[i];
        std::cout << "average: " << ada[i].Average() << std::endl;
    }
    std::cout << "Done." << std::endl;
}

void set(Student& sa, int n) {
    std::cout << "Please enter the student's name: ";
    getline(std::cin, sa);
    std::cout << "Please enter " << n << " quiz scores:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> sa[i];
    }
    while (std::cin.get() != '\n')
    {
        continue;
    }
}
