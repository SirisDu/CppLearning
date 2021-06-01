// stcktp1.h
// modified Stack template

#pragma once

template <typename Type>
class Stack
{
public:
	explicit Stack(int ss = SIZE);
	Stack(const Stack& st);
	~Stack() { delete[] items_; }

	bool isempty() const { return top_ == 0; }
	bool isfull() const { return top_ == stacksize_; }
	bool push(const Type& item);     // add item to stack
	bool pop(Type& item);            // pop top into item

	Stack& operator=(const Stack& st);

private:
	enum { SIZE = 10 };              // default size
	int stacksize_;
	Type* items_;                    // holds stack items
	int top_;                        // index for top stack item
};

template <typename Type>
Stack<Type>::Stack(int ss) : stacksize_(ss), top_(0)
{
	items_ = new Type[stacksize_];
}

template <typename Type>
Stack<Type>::Stack(const Stack& st)
{
	stacksize_ = st.stacksize_;
	top_ = st.top_;
	items_ = new Type[stacksize_];
	for (int i = 0; i < top_; i++)
	{
		items_[i] = st.items_[i];
	}
}

template <typename Type>
bool Stack<Type>::push(const Type& item)
{
	if (top_ < stacksize_)
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

template <typename Type>
Stack<Type>& Stack<Type>::operator=(const Stack<Type>& st)
{
	if (this == &st)
	{
		return *this;
	}
	else
	{
		delete[] items_;
		stacksize_ = st.stacksize_;
		top_ = st.top_;
		items_ = new Type[stacksize_];
		for (int i = 0; i < top_; i++)
		{
			items_[i] = st.items_[i];
		}

		return *this;
	}
}
