// pairs.cpp
// defining and using a Pair template

#include <iostream>
#include <string>

template <typename T1, typename T2>
class Pair
{
public:
	Pair() {}
	Pair(const T1& aval, const T2& bval) : a(aval), b(bval) {}
	virtual ~Pair() {}

	T1& first() { return a; }
	T2& second() { return b; }
	T1 first() const { return a; }
	T2 second() const { return b; }

private:
	T1 a;
	T2 b;
};

int main()
{
	Pair<std::string, int> ratings[4]{
		Pair<std::string, int>("The Purpled Duck", 5),
		Pair<std::string, int>("Jaquie's Frisco AI Fresco", 4),
		Pair<std::string, int>("Cafe Souffle", 5),
		Pair<std::string, int>("Bertie's Eats", 3)
	};

	int joints{ sizeof(ratings) / sizeof(Pair<std::string, int>) };
	std::cout << "Rating:\t Eatery\n";
	for (int i = 0; i < joints; i++)
	{
		std::cout << ratings[i].second() << ":\t "
			<< ratings[i].first() << std::endl;
	}
	std::cout << "Oops! Revised rating:" << std::endl;
	ratings[3].first() = "Bertie's Fab Eats";
	ratings[3].second() = 6;
	std::cout << ratings[3].second() << ":\t "
		<< ratings[3].first() << std::endl;
}
