// stacktp.h
// a stack template

#pragma once

template <typename Type>
class Stack
{
public:
	Stack();
	~Stack();

	bool isempty() const;
	bool isfull() const;
	bool push(const Type& item);  // add item to stack
	bool pop(Type& item);         // pop top into item

private:
	enum { MAX = 10 };            // constant specific to class
	Type items_[MAX];             // holds stack items
	int top_;                     // index for top stack item
};

template <typename Type>
Stack<Type>::Stack()
{
	top_ = 0;
}

template <typename Type>
Stack<Type>::~Stack()
{

}

template <typename Type>
bool Stack<Type>::isempty() const
{
	return top_ == 0;
}

template <typename Type>
bool Stack<Type>::isfull() const
{
	return top_ == MAX;
}

template <typename Type>
bool Stack<Type>::push(const Type& item)
{
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

template <typename Type>
bool Stack<Type>::pop(Type& item)
{
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
