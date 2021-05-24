// bank.cpp
// using the Queue interface

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

const int MIN_PER_HR{ 60 };

bool newcustomer(double x);                   // is there a new customer?

int main()
{
    // setting things up
    std::srand(std::time(0));                 // random initializing of rand()

    std::cout << "Case Study: Bank of Heather Automatic Teller" << std::endl;
    std::cout << "Enter maximum size of queue: ";
    int qs{};
    std::cin >> qs;
    Queue line(qs);                           // line queue holds up to qs people

    std::cout << "Enter the number of simulation hours: ";
    int hours{};                              // hours of simulation
    std::cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit{ MIN_PER_HR * hours };    // # of cycles

    std::cout << "Enter the average number of customers per hour: ";
    double perhour{};                         // average # of arrival per hour
    std::cin >> perhour;
    double min_per_customer{};                // average time between arrivals
    min_per_customer = MIN_PER_HR / perhour;
    
    Item temp;                                // new customer data
    long turnaways{};                         // turned away by full queue
    long customers{};                         // joined the queue
    long served{};                            // served during the simulation
    long sum_line{};                          // cumulative line length
    int wait_time{};                          // time until autoteller is free
    long line_wait{};                         // cumulative time in line

    // running the simulation
    for (int cycle = 0; cycle < cyclelimit; ++cycle)
    {
        if (newcustomer(min_per_customer))    // have newcomer
        {
            if (line.isfull())
            {
                ++turnaways;
            }
            else
            {
                ++customers;
                temp.set(cycle);              // cycle = time of arrival
                line.enqueue(temp);           // add newcomer to line
            }
        }
        if (wait_time <= 0 && !line.isempty())
        {
            line.dequeue(temp);               // attend next customer
            wait_time = temp.ptime();         // for wait_time minutes
            line_wait += cycle - temp.when();
            ++served;
        }
        if (wait_time > 0)
        {
            --wait_time;
        }
        sum_line += line.queuecount();
    }

    // reporting results
    if (customers > 0)
    {
        std::cout << "customers accepted: " << customers << std::endl;
        std::cout << "  customers served: " << served << std::endl;
        std::cout << "         turnaways: " << turnaways << std::endl;
        std::cout << "average queue size: ";
        std::cout.precision(2);
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::cout << double(sum_line) / cyclelimit << std::endl;
        std::cout << " average wait time: "
            << double(line_wait) / served << " minutes" << std::endl;
    }
    else
    {
        std::cout << "No customers!" << std::endl;
    }
    std::cout << "Done!" << std::endl;
}

bool newcustomer(double x) {
    return (std::rand() * x / RAND_MAX < 1);
}
