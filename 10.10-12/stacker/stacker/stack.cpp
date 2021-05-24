// stack.cpp
// Stack member functions

#include "stack.h"

Stack::Stack() {              // create an empty stack
	top_ = 0;
}

Stack::~Stack() {

}

bool Stack::isempty() const {
	return top_ == 0;
}

bool Stack::isfull() const {
	return top_ == MAX;
}

bool Stack::push(const Item& item) {
	if (top_ < MAX)
	{
		items_[top_++] = item;
		return true;
	}
	else
	{
		return false;
	}
}

bool Stack::pop(Item& item) {
	if (top_ > 0)
	{
		item = items_[--top_];
		return true;
	}
	else
	{
		return false;
	}
}
