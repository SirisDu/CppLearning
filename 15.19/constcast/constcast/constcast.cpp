// constcast.cpp
// using const_cast<>

#include <iostream>

void change(const int* pt, int n);

int main()
{
    int pop1{ 38383 };
    const int pop2{ 2000 };

    std::cout << "pop1, pop2: " << pop1 << ", " << pop2 << std::endl;
    change(&pop1, -103);
    change(&pop2, 103);
    std::cout << "pop1, pop2: " << pop1 << ", " << pop2 << std::endl;
}

void change(const int* pt, int n)
{
    int* pc;

    pc = const_cast<int*>(pt);
    *pc += n;
}
