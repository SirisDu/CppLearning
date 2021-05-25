// two_atm.cpp
// simulate two ATMs

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
    Queue line1(qs);                          // line queue #1 holds up to qs people
    Queue line2(qs);                          // line queue #2 holds up to qs people

    std::cout << "Enter the number of simulation hours: ";
    int hours{};                              // hours of simulation
    std::cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit{ MIN_PER_HR * hours };    // # of cycles

    double perhour{};                         // average # of arrival per hour
    perhour = 1;
    double min_per_customer{};                // average time between arrivals
    min_per_customer = MIN_PER_HR / perhour;

    long turnaways{};                         // turned away by full queue
    long customers{};                         // joined the queue
    long served1{ 1 };                        // line1 served during the simulation
    long served2{ 1 };                        // line2 served during the simulation
    long sum_line{};                          // cumulative line length
    int wait_time1{};                         // time until autoteller #1 is free
    int wait_time2{};                         // time until autoteller #2 is free
    long line_wait{};                         // cumulative time in line
    double average{};
    double desired_average{};

    average = double(line_wait) / (served1 + served2);
    std::cout << "Enter the desired average wait time: ";
    std::cin >> desired_average;
    while (std::cin.get() != '\n')
    {
        continue;
    }

    while (average < 0.95 * desired_average || average > 1.05 * desired_average)
    {
        Item temp;                            // new customer data
        turnaways = 0;
        customers = 0;
        served1 = 0;
        served2 = 0;
        sum_line = 0;
        wait_time1 = 0;
        wait_time2 = 0;
        line_wait = 0;
        perhour = std::rand() % 100 + 1;
        min_per_customer = MIN_PER_HR / perhour;

        // running the simulation
        for (int cycle = 0; cycle < cyclelimit; ++cycle)
        {
            if (newcustomer(min_per_customer))// have newcomer
            {
                if (line1.isfull() && line2.isfull())
                {
                    ++turnaways;
                }
                else
                {
                    ++customers;
                    temp.set(cycle);          // cycle = time of arrival
                    if (line1.queuecount() < line2.queuecount())
                    {
                        line1.enqueue(temp);  // add newcomer to line #1
                    }
                    else
                    {
                        line2.enqueue(temp);  // else add newcomer to line #2
                    }
                }
            }
            if (wait_time1 <= 0 && !line1.isempty())
            {
                line1.dequeue(temp);          // attend next customer
                wait_time1 = temp.ptime();    // for wait_time minutes
                line_wait += cycle - temp.when();
                ++served1;
            }
            if (wait_time1 > 0)
            {
                --wait_time1;
            }
            if (wait_time2 <= 0 && !line2.isempty())
            {
                line2.dequeue(temp);          // attend next customer
                wait_time2 = temp.ptime();    // for wait_time minutes
                line_wait += cycle - temp.when();
                ++served2;
            }
            if (wait_time2 > 0)
            {
                --wait_time2;
            }
            sum_line += line1.queuecount() + line2.queuecount();
        }
        average = double(line_wait) / (served1 + served2);
    }

    // reporting results
    if (customers > 0)
    {
        std::cout << "         customers accepted: " << customers << std::endl;
        std::cout << "customers served in line #1: " << served1 << std::endl;
        std::cout << "customers served in line #2: " << served2 << std::endl;
        std::cout << "               total served: " << served1 + served2 << std::endl;
        std::cout << "                  turnaways: " << turnaways << std::endl;
        std::cout << "            average arrival: " << perhour << std::endl;
        std::cout << "         average queue size: ";
        std::cout.precision(2);
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::cout << double(sum_line) / cyclelimit << std::endl;
        std::cout << "          average wait time: "
            << average << " minutes" << std::endl;
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
