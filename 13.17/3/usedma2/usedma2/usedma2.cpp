// usedma2.cpp
// abstract base class combinede with DMA

#include <iostream>
#include "dma2.h"

const int Numbers{ 4 };

int main()
{
    baseABC* p_dma[Numbers];
    char temp_label[40]{};
    int temp_rating{};
    char kind{};

    for (int i = 0; i < Numbers; i++)
    {
        std::cout << "Enter label: ";
        std::cin.getline(temp_label, 40);
        std::cout << "Enter rating: ";
        std::cin >> temp_rating;
        std::cin.get();
        std::cout << "Enter 0 for baseDMA, "
            "or 1 for lacksDMA, "
            "or 2 for hasDMA: ";
        std::cin >> kind;
        std::cin.get();
        while (kind != '0' && kind != '1' && kind != '2')
        {
            std::cout << "Enter 0, 1, or 2: ";
            std::cin >> kind;
            std::cin.get();
        }
        if (kind == '0')
        {
            p_dma[i] = new baseDMA(temp_label, temp_rating);
        }
        else if (kind == '1')
        {
            char temp_color[40]{};

            std::cout << "Enter color: ";
            std::cin.getline(temp_color, 40);
            p_dma[i] = new lacksDMA(temp_color, temp_label, temp_rating);
        }
        else
        {
            char temp_style[40]{};

            std::cout << "Enter style: ";
            std::cin.getline(temp_style, 40);
            p_dma[i] = new hasDMA(temp_style, temp_label, temp_rating);
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < Numbers; i++)
    {
        p_dma[i]->View();
        std::cout << std::endl;
    }
    for (int i = 0; i < Numbers; i++)
    {
        delete p_dma[i];
    }
    std::cout << "Done." << std::endl;
}
