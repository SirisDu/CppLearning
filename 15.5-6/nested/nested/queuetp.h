// queuetp.h
// queue template with a nested class

#pragma once

template <typename Item>
class QueueTP
{
public:
	QueueTP(int qs = Q_SIZE);        // create queue with a qs limit
	~QueueTP();

	bool isempty() const { return items_ == 0; }
	bool isfull() const { return items_ == qsize_; }
	int queuecount() const { return items_; }
	bool enqueue(const Item& item);  // add item to end
	bool dequeue(Item& item);        // remove item from front

private:
	enum { Q_SIZE = 10 };
	// Node is a nested class definition
	class Node
	{
	public:
		Item item_;
		Node* next_;
		Node(const Item& item) : item_(item), next_(nullptr) {}
		~Node() {}
	};
	Node* front_;                    // pointer to front of Queue
	Node* rear_;                     // pointer to rear of Queue
	int items_;                      // current number of items in Queue
	const int qsize_;                // maximum number of items in Queue

	// preemptive definitions to prevent public copying
	QueueTP(const QueueTP& queue) : qsize_(0) {}
	QueueTP& operator=(const QueueTP& queue) { return *this; }
};

// QueueTP methods
template <typename Item>
QueueTP<Item>::QueueTP(int qs) : qsize_(qs) {
	front_ = rear_ = nullptr;
	items_ = 0;
}

template <typename Item>
QueueTP<Item>::~QueueTP() {
	Node* temp;
	while (front_ != nullptr)        // while queue is not yet empty
	{
		temp = front_;               // save address of front item
		front_ = front_->next_;      // reset pointer to next item
		delete temp;                 // delete former front
	}
}

// add item to queue
template <typename Item>
bool QueueTP<Item>::enqueue(const Item& item) {
	if (isfull())
	{
		return false;
	}
	Node* add = new Node(item);      // create node
	// on failure, new throws std::bad alloc exception
	++items_;
	if (front_ == nullptr)           // if queue is empty
	{
		front_ = add;                // place item at front
	}
	else
	{
		rear_->next_ = add;          // else place at rear
	}
	rear_ = add;                     // have rear point to new node

	return true;
}

// Place front item into item variable and remove from queue
template <typename Item>
bool QueueTP<Item>::dequeue(Item& item) {
	if (front_ == nullptr)
	{
		return false;
	}
	item = front_->item_;            // set item to first item in queue
	--items_;
	Node* temp = front_;             // save location of first item
	front_ = front_->next_;          // reset front to next item
	delete temp;                     // delete former first item
	if (items_ == 0)
	{
		rear_ = nullptr;
	}

	return true;
}
