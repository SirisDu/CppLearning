// manyfrnd.cpp
// unbound template friend to a template class

#include <iostream>

template <typename T>
class ManyFriend
{
public:
	ManyFriend(const T& i) : item(i) {}
	~ManyFriend() {}

	template <typename C, typename D> friend void show2(C& c, D& d);

private:
	T item;
};

template <typename C, typename D>
void show2(C& c, D& d)
{
	std::cout << c.item << ", " << d.item << std::endl;
}

int main()
{
	ManyFriend<int> hfi1(10);
	ManyFriend<int> hfi2(20);
	ManyFriend<double> hfdb(10.5);
	std::cout << "hfi1, hfi2: ";
	show2(hfi1, hfi2);
	std::cout << "hfdb, hfi2: ";
	show2(hfdb, hfi2);
}
