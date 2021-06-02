// tempmemb.cpp
// template members

#include <iostream>

template <typename T>
class beta
{
public:
	beta(T t, int i) : q(t), n(i) {}
	virtual ~beta() {}

	template<typename U>
	U blab(U u, T t) { return (n.value() + q.value()) * u / t; }
	void Show() const { q.show(); n.show(); }

private:
	template <typename V>       // nested template class member
	class hold
	{
	public:
		hold(V v = 0) : val(v) {}
		virtual ~hold() {}

		void show() const { std::cout << val << std::endl; }
		V value() const { return val; }

	private:
		V val;
	};
	hold<T> q;                  // template object
	hold<int> n;                // template object
};

int main()
{
	beta<double> guy(3.5, 3);
	
	std::cout << "T was set to double." << std::endl;
	guy.Show();
	std::cout << "V was set to T, which is double, then V was set to int.\n";
	std::cout << guy.blab(10, 2.3) << std::endl;
	std::cout << "U was set to int." << std::endl;
	std::cout << guy.blab(10.0, 2.3) << std::endl;
	std::cout << "U was set to double." << std::endl;
	std::cout << "Done." << std::endl;
}
