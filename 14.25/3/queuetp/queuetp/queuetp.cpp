// queuetp.cpp
// using Worker classes with Queue template

#include <iostream>
#include "queue.h"
#include "workermi.h"

int main()
{
    // get queue length
    int queue_length{};
    std::cout << "Enter queue length: ";
    std::cin >> queue_length;
    // declare a queue with queue_length workers
    Queue<Worker*> p_workers(queue_length);

    char ch{};
    std::cout << "Please enter E to process an enqueue," << std::endl
        << "D to process a dequeue, or Q to quit." << std::endl;
    // loop until met q/Q
    while (std::cin >> ch && toupper(ch) != 'Q')
    {
        while (std::cin.get() != '\n')
        {
            continue;
        }           // get rid of redundent characters
        if (!isalpha(ch))
        {
            std::cout << '\a';
            continue;
        }           // ensure input is a character
        switch (ch)
        {
        case 'e':
        case 'E':
            if (p_workers.isfull())
            {
                std::cout << "Queue already full!" << std::endl;
                continue;
            }
            else
            {
                char choice{};
                Worker* temp;
                std::cout << "Enter the employee category:" << std::endl
                    << "w: waiter  s: singer  t: singing waiter" << std::endl;
                std::cin >> choice;
                while (strchr("wst", choice) == nullptr)
                {
                    std::cout << "Please enter a w, s, or t: ";
                    std::cin >> choice;
                }
                switch (choice)
                {
                case 'w':
                    temp = new Waiter;
                    std::cin.get();
                    temp->Set();
                    break;
                case 's':
                    temp = new Singer;
                    std::cin.get();
                    temp->Set();
                    break;
                case 't':
                    temp = new SingerWaiter;
                    std::cin.get();
                    temp->Set();
                    break;
                }
                p_workers.enqueue(temp);
                std::cout << p_workers.queuecount() << " workers in queue.\n";
            }
            break;
        case 'd':
        case 'D':
            if (p_workers.isempty())
            {
                std::cout << "Queue already empty!" << std::endl;
                continue;
            }
            else
            {
                Worker* temp;
                p_workers.dequeue(temp);
                std::cout << "This worker out of line:" << std::endl;
                temp->Show();
                delete temp;
                std::cout << p_workers.queuecount() << " workers in queue.\n";
            }
            break;
        default:
            break;
        }
        std::cout << "Please enter E to process an enqueue," << std::endl
            << "D to process a dequeue, or Q to quit." << std::endl;
    }
    std::cout << "Bye" << std::endl;
}
