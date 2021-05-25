// stack.h
// class definition for the stack ADT

#pragma once

typedef unsigned long Item;

class Stack
{
public:
	Stack(int n = MAX);                   // creates stack with n elements
	Stack(const Stack& st);               // copy constructor
	~Stack();                             // destructor

	bool isempty() const;
	bool isfull() const;
	// push() returns false if stack already is full, true otherwise
	bool push(const Item& item);          // add item to stack
	// pop() returns false if stack already is empty, true otherwise
	bool pop(Item& item);                 // pop top into item

	Stack& operator=(const Stack& st);    // assignment overloaded

private:
	enum { MAX = 10 };                    // constant specific to class
	Item* pitems_;                        // holds stack items
	int size_;                            // number of elements in stack
	int top_;                             // index for top stack item
};
