// vect2.cpp
// methods and iterators

#include <iostream>
#include <string>
#include <vector>

struct Review
{
    std::string title;
    int rating;
};

bool FillReview(Review& rev);
void ShowReview(const Review& rev);

int main()
{
    std::vector<Review> books;
    Review temp;
    while (FillReview(temp))
    {
        books.push_back(temp);
    }

    int num = books.size();
    if (num > 0)
    {
        std::cout << "Thank you. You entered the following:" << std::endl
            << "Rating\tBook" << std::endl;
        for (int i = 0; i < num; i++)
        {
            ShowReview(books[i]);
        }
        std::cout << "Reprising:" << std::endl
            << "Rating\tBook" << std::endl;
        std::vector<Review>::iterator pr;
        for (pr = books.begin(); pr != books.end(); ++pr)
        {
            ShowReview(*pr);
        }
        std::vector<Review> oldlist(books);         // copy constructor used
        if (num > 3)
        {
            // remove 2 items
            books.erase(books.begin() + 1, books.begin() + 3);
            std::cout << "After erasure:" << std::endl;
            for (pr = books.begin(); pr != books.end(); ++pr)
            {
                ShowReview(*pr);
            }
            // insert 1 item
            books.insert(books.begin(), oldlist.begin() + 1,
                oldlist.begin() + 2);
            std::cout << "After insertion:" << std::endl;
            for (pr = books.begin(); pr != books.end(); ++pr)
            {
                ShowReview(*pr);
            }
        }
        books.swap(oldlist);
        std::cout << "Swapping oldlist with books:" << std::endl;
        for (pr = books.begin(); pr != books.end(); ++pr)
        {
            ShowReview(*pr);
        }
    }
    else
    {
        std::cout << "Nothing entered, nothing gained." << std::endl;
    }
}

bool FillReview(Review& rev)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rev.title);
    if (rev.title == "quit")
    {
        return false;
    }
    std::cout << "Enter book rating: ";
    std::cin >> rev.rating;
    if (!std::cin)
    {
        return false;
    }
    // get rid of rest of input line
    while (std::cin.get() != '\n')
    {
        continue;
    }
    return true;
}

void ShowReview(const Review& rev)
{
    std::cout << rev.rating << "\t" << rev.title << std::endl;
}
