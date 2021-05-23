// placenew1.cpp
// new, placement new, no delete

#include <iostream>
#include <string>
#include <new>

const int BUF{ 512 };

class JustTesting
{
public:
	JustTesting(const std::string& s = "Just Testing", int n = 0) {
		words_ = s;
		number_ = n;
		std::cout << words_ << " constructed" << std::endl;
	}
	~JustTesting() {
		std::cout << words_ << " destroyed" << std::endl;
	}
	void Show() const {
		std::cout << words_ << ", " << number_ << std::endl;
	}

private:
	std::string words_;
	int number_;
};

int main()
{
	char* buffer = new char[BUF];           // get a block of memory
	JustTesting* pc1;
	JustTesting* pc2;

	pc1 = new (buffer) JustTesting;         // place object in buffer
	pc2 = new JustTesting("Heap1", 20);     // place object on heap

	std::cout << "Memory block addresses:" << std::endl << "buffer: "
		<< (void*)buffer << "    heap: " << pc2 << std::endl;
	std::cout << "Memory contents:" << std::endl;
	std::cout << pc1 << ": ";
	pc1->Show();
	std::cout << pc2 << ": ";
	pc2->Show();

	JustTesting* pc3;
	JustTesting* pc4;

	pc3 = new (buffer) JustTesting("Bad Idea", 6);
	pc4 = new JustTesting("Heap2", 10);

	std::cout << "Memory contents:" << std::endl;
	std::cout << pc3 << ": ";
	pc3->Show();
	std::cout << pc4 << ": ";
	pc4->Show();

	delete pc2;                             // free Heap1
	delete pc4;                             // free Heap2
	delete[] buffer;                        // free buffer
	std::cout << "Done." << std::endl;
}
