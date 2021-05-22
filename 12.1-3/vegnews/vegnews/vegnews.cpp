// vegnews.cpp
// using new and delete with classes

#include <iostream>
#include "strngbad.h"

void callme1(StringBad& rsb);
void callme2(StringBad sb);

int main()
{
    {
        std::cout << "Starting an inner block." << std::endl;
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");
        std::cout << "headline1: " << headline1 << std::endl;
        std::cout << "headline2: " << headline2 << std::endl;
        std::cout << "sports: " << sports << std::endl;
        callme1(headline1);
        std::cout << "headline1: " << headline1 << std::endl;
        callme2(headline2);
        std::cout << "headline2: " << headline2 << std::endl;
        std::cout << "Initialize one object to another:" << std::endl;
        StringBad sailor = sports;
        std::cout << "sailor: " << sailor << std::endl;
        std::cout << "Assign one object to another:" << std::endl;
        StringBad knot;
        std::cout << "knot: " << knot << std::endl;
        std::cout << "Exiting the block." << std::endl;
    }
    std::cout << "End of main()" << std::endl;
    
}

void callme1(StringBad& rsb) {
    std::cout << "String passed by reference:" << std::endl;
    std::cout << "    \"" << rsb << "\"" << std::endl;
}

void callme2(StringBad sb) {
    std::cout << "String passed by value:" << std::endl;
    std::cout << "    \"" << sb << "\"" << std::endl;
}
