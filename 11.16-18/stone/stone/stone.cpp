// stone.cpp
// user-defined conversions

#include <iostream>
#include "stonewt.h"

void display(const Stonewt& st, int n);

int main()
{
	Stonewt incognito = 275;         // uses constructor to initialize
	Stonewt wolfe(285.7);            // same as Stonewt wolfe = 285.7;
	Stonewt taft(21, 8);

	std::cout << "The celebrity weighed ";
	incognito.show_stn();
	std::cout << "The detective weighed ";
	wolfe.show_stn();
	std::cout << "The President weighed ";
	taft.show_lbs();
	incognito = 276.8;               // uses constructor for conversion
	taft = 325;                      // same as taft = Stonewt(325);
	std::cout << "After dinner, the celebrity weighed ";
	incognito.show_stn();
	std::cout << "After dinner, the President weighed ";
	taft.show_lbs();
	display(taft, 2);
	std::cout << "The wrestler weighed even more." << std::endl;
	display(422, 2);
	std::cout << "No stone left unearned" << std::endl;
}

void display(const Stonewt& st, int n) {
	for (int i = 0; i < n; i++)
	{
		std::cout << "Wow! ";
		st.show_stn();
	}
}
