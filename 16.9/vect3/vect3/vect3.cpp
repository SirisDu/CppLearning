// vect3.cpp
// using STL functions

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review
{
    std::string title;
    int rating;
};

bool operator<(const Review& r1, const Review& r2);
bool worseThan(const Review& r1, const Review& r2);
bool FillReview(Review& r);
void ShowReview(const Review& r);

int main()
{
    std::vector<Review> books;
    Review temp;

    while (FillReview(temp))
    {
        books.push_back(temp);
    }
    if (books.size() > 0)
    {
        std::cout << "Thank you. You entered the following "
            << books.size() << " ratings:" << std::endl
            << "Rating\tBook" << std::endl;
        std::for_each(books.begin(), books.end(), ShowReview);

        std::sort(books.begin(), books.end());
        std::cout << "Sorted by title:\nRating\tBook\n";
        std::for_each(books.begin(), books.end(), ShowReview);

        std::sort(books.begin(), books.end(), worseThan);
        std::cout << "Sorted by rating:\nRating\tBook\n";
        std::for_each(books.begin(), books.end(), ShowReview);

        std::random_shuffle(books.begin(), books.end());
        std::cout << "After shuffling:\nRating\tBook\n";
        std::for_each(books.begin(), books.end(), ShowReview);
    }
    else
    {
        std::cout << "No entries. ";
    }
    std::cout << "Bye!" << std::endl;
}

bool operator<(const Review& r1, const Review& r2)
{
    if (r1.title < r2.title)
    {
        return true;
    }
    else if (r1.title == r2.title && r1.rating < r2.rating)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool worseThan(const Review& r1, const Review& r2)
{
    if (r1.rating < r2.rating)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool FillReview(Review& r)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, r.title);
    if (r.title == "quit")
    {
        return false;
    }
    std::cout << "Enter book rating: ";
    std::cin >> r.rating;
    if (!std::cin)
    {
        return false;
    }
    // get rid of reset of input line
    while (std::cin.get() != '\n')
    {
        continue;
    }
    return true;
}

void ShowReview(const Review& r)
{
    std::cout << r.rating << "\t" << r.title << std::endl;
}
