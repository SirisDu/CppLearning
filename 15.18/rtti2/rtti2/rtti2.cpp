﻿// rtti2.cpp
// using dynamic_cast, typeid, and type_info

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

class Grand
{
public:
	Grand(int h = 0) : hold(h) {}
	virtual ~Grand() {}

	virtual void Speak() const { std::cout << "I am a grand class!\n"; }
	virtual int Value() const { return hold; }

private:
	int hold;
};

class Superb : public Grand
{
public:
	Superb(int h = 0) : Grand(h) {}
	virtual ~Superb() {}

	void Speak() const { std::cout << "I am a superb class!!\n"; }
	virtual void Say() const
	{
		std::cout << "I hold the superb value of " << Value() << "!\n";
	}
};

class Magnificent : public Superb
{
public:
	Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
	virtual ~Magnificent() {}

	void Speak() const { std::cout << "I am a magnificent class!!!\n"; }
	void Say() const
	{
		std::cout << "I hold the character " << ch
			<< " and the integer " << Value() << "!\n";
	}

private:
	char ch;
};

Grand* GetOne();

int main()
{
	std::srand(std::time(0));
	Grand* pg;
	Superb* ps;
	for (int i = 0; i < 5; i++)
	{
		pg = GetOne();
		std::cout << "Now processing type " << typeid(*pg).name() << std::endl;
		pg->Speak();
		if (ps = dynamic_cast<Superb*>(pg))
		{
			ps->Say();
		}
		if (typeid(Magnificent) == typeid(*pg))
		{
			std::cout << "Yes, you're really magnificent." << std::endl;
		}
	}
}

Grand* GetOne()
{
	Grand* p;
	switch (std::rand() % 3)
	{
	case 0:
		p = new Grand(std::rand() % 100);
		return p;
	case 1:
		p = new Superb(std::rand() % 100);
		return p;
	case 2:
		p = new Magnificent(std::rand() % 100, 'A' + std::rand() % 26);
		return p;
	}
}
