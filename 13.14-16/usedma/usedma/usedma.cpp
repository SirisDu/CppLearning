// usedma.cpp
// inheritance, friends, and DMA

#include <iostream>
#include "dma.h"

int main()
{
    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    std::cout << "Displaying baseDMA object:" << std::endl;
    std::cout << shirt << std::endl;
    std::cout << "Displaying lacksDMA object:" << std::endl;
    std::cout << balloon << std::endl;
    std::cout << "Displaying hasDMA object:" << std::endl;
    std::cout << map << std::endl;
    lacksDMA balloon2(balloon);
    std::cout << "Result of lacksDMA copy:" << std::endl;
    std::cout << balloon2 << std::endl;
    hasDMA map2;
    map2 = map;
    std::cout << "Result of hasDMA assignment:" << std::endl;
    std::cout << map2 << std::endl;
}
