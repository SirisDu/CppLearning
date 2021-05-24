// stack.h
// class definition for stack ADT

#pragma once

typedef unsigned long Item;

class Stack
{
public:
	Stack();
	~Stack();

	bool isempty() const;
	bool isfull() const;
	// push() returns false if stack already is full, true otherwise
	bool push(const Item& item);          // add item to stack
	// pop() returns false if stack already is empty, true otherwise
	bool pop(Item& item);                 // pop top into item

private:
	enum { MAX = 10 };                    // constant specific to class
	Item items_[MAX];                     // holds stack items
	int top_;                             // index for top stack item
};
