// use_tv3.cpp
// Tv and Remote friends with each other

#include <iostream>
#include "tv.h"

int main()
{
    Tv s42;
    Remote grey;

    std::cout << "Initial setting for 42\" TV:" << std::endl;
    s42.settings();
    std::cout << "Trying to change remote mode when TV is off:" << std::endl;
    s42.change_remote_mode(grey);
    grey.show_mode();

    s42.onoff();
    s42.chanup();
    std::cout << std::endl << "Adjusted settings for 42\" TV:" << std::endl;
    s42.settings();
    std::cout << std::endl << "Adjusted modes for grey\" TV:" << std::endl;
    s42.change_remote_mode(grey);
    grey.show_mode();

    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    std::cout << std::endl << "42\" settings after using remote:" << std::endl;
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    std::cout << std::endl << "58\" settings:" << std::endl;
    s58.settings();
}
