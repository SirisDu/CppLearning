// frnd2tmp.cpp
// template class with non-template friends

#include <iostream>

template <typename T>
class HasFriend
{
public:
	HasFriend(const T& i) : item(i) { ++ct; }
	~HasFriend() { --ct; }

	friend void counts();
	friend void reports(HasFriend<T>& hf);       // template parameter

private:
	T item;
	static int ct;
};

// each specialization has its own static data member
template <typename T>
int HasFriend<T>::ct{ 0 };

// non-template friend to all HasFriend<T> classes
void counts()
{
	std::cout << "int count: " << HasFriend<int>::ct << "; ";
	std::cout << "double count: " << HasFriend<double>::ct << std::endl;
}

// non-template friend to all HasFriend<int> class
void reports(HasFriend<int>& hf)
{
	std::cout << "HasFriend<int>: " << hf.item << std::endl;
}

// non-template friend to all HasFriend<double> class
void reports(HasFriend<double>& hf)
{
	std::cout << "HasFriend<double>: " << hf.item << std::endl;
}

int main()
{
	std::cout << "No object declared: ";
	counts();
	HasFriend<int> hfi1(10);
	std::cout << "After hfi1 declared: ";
	counts();
	HasFriend<int> hfi2(20);
	std::cout << "After hfi2 declared: ";
	counts();
	HasFriend<double> hfdb(10.5);
	std::cout << "After hfdb declared: ";
	counts();
	reports(hfi1);
	reports(hfi2);
	reports(hfdb);
}
