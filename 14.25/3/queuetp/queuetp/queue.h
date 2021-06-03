// queue.h
// Queue template

#pragma once

template <typename Type>
class Queue
{
public:
	// create queue with a qs limit
	Queue(int qs = Q_SIZE) : qsize_(qs)
	{
		front_ = rear_ = nullptr;
		items_ = 0;
	}
	~Queue()
	{
		Node* temp;
		while (front_ != nullptr)    // while queue is not yet empty
		{
			temp = front_;           // save address of front item
			front_ = front_->next_;  // reset pointer to next item
			delete temp;             // delete former front
		}
	}

	bool isempty() const { return items_ == 0; }
	bool isfull() const { return items_ == qsize_; }
	int queuecount() const { return items_; }
	// add item to queue
	bool enqueue(const Type& item)   // add item to end
	{
		if (isfull())
		{
			return false;
		}
		Node* add = new Node;        // create node
		// on failure, new throws std::bad alloc exception
		add->item_ = item;           // set node pointers
		add->next_ = nullptr;
		++items_;
		if (front_ == nullptr)       // if queue is empty
		{
			front_ = add;            // place item at front
		}
		else
		{
			rear_->next_ = add;      // else place at rear
		}
		rear_ = add;                 // have rear point to new node

		return true;
	}
	// Place front item into item variable and remove from queue
	bool dequeue(Type& item)         // remove item from front
	{
		if (front_ == nullptr)
		{
			return false;
		}
		item = front_->item_;        // set item to first item in queue
		--items_;
		Node* temp = front_;         // save location of first item
		front_ = front_->next_;      // reset front to next item
		delete temp;                 // delete former first item
		if (items_ == 0)
		{
			rear_ = nullptr;
		}

		return true;
	}

private:
	struct Node
	{
		Type item_;
		struct Node* next_;
	};
	enum { Q_SIZE = 10 };
	Node* front_;                    // pointer to front of Queue
	Node* rear_;                     // pointer to rear of Queue
	int items_;                      // current number of items in Queue
	const int qsize_;                // maximum number of items in Queue
	// preemptive definitions to prevent public copying
	Queue(const Queue& q) : qsize_(0)
	{
		front_ = rear_ = nullptr;
		items_ = 0;
	}
	Queue& operator=(const Queue& q) { return *this; }
};
