// tmp2tmp.cpp
// template friends to a template class

#include <iostream>

// template prototypes
template <typename T> void counts();
template <typename T> void report(T& hf);

// template class
template <typename TT>
class HasFriendT
{
public:
	HasFriendT(const TT& i) : item(i) { ++ct; }
	~HasFriendT() { --ct; }

	friend void counts<TT>();
	friend void report<>(HasFriendT<TT>& hf);

private:
	TT item;
	static int ct;
};

template <typename T>
int HasFriendT<T>::ct{ 0 };

// template friend functions definition
template <typename T>
void counts()
{
	std::cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
	std::cout << "template counts(): " << HasFriendT<T>::ct << std::endl;
}

template <typename T>
void report(T& hf)
{
	std::cout << hf.item << std::endl;
}

int main()
{
	counts<int>();
	HasFriendT<int> hfi1(10);
	HasFriendT<int> hfi2(20);
	HasFriendT<double> hfdb(10.5);
	report(hfi1);         // generate report(HasFriend<int>&)
	report(hfi2);         // generate report(HasFriend<int>&)
	report(hfdb);         // generate report(HasFriend<double>&)
	std::cout << "counts<int>() output:" << std::endl;
	counts<int>();
	std::cout << "counts<double>() output:" << std::endl;
	counts<double>();
}
