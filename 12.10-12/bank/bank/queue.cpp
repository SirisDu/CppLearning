// queue.cpp
// Queue and Customer methods

#include <cstdlib>
#include "queue.h"

// Queue methods
Queue::Queue(int qs) : qsize(qs) {
	front_ = rear_ = nullptr;
	items_ = 0;
}

Queue::~Queue() {
	Node* temp;
	while (front_ != nullptr)          // while queue is not yet empty
	{
		temp = front_;                 // save address of front item
		front_ = front_->next;         // reset pointer to next item
		delete temp;                   // delete former front
	}
}

bool Queue::isempty() const {
	return items_ == 0;
}

bool Queue::isfull() const {
	return items_ == qsize;
}

int Queue::queuecount() const {
	return items_;
}

// add item to queue
bool Queue::enqueue(const Item& item) {
	if (isfull())
	{
		return false;
	}
	Node* add = new Node;              // create node
	// on failure, new throws std::bad alloc exception
	add->item = item;                  // set node pointers
	add->next = nullptr;
	++items_;
	if (front_ == nullptr)             // if queue is empty
	{
		front_ = add;                  // place item at front
	}
	else
	{
		rear_->next = add;             // else place at rear
	}
	rear_ = add;                       // have rear point to new node

	return true;
}

// Place front item into item variable and remove from queue
bool Queue::dequeue(Item& item) {
	if (front_ == nullptr)
	{
		return false;
	}
	item = front_->item;               // set item to first item in queue
	--items_;
	Node* temp = front_;               // save location of first item
	front_ = front_->next;             // reset front to next item
	delete temp;                       // delete former first item
	if (items_ == 0)
	{
		rear_ = nullptr;
	}

	return true;
}

// private Queue methods
Queue::Queue(const Queue& q) : qsize(0) {

}

Queue& Queue::operator=(const Queue& q) {
	return *this;
}

// Customer methods
Customer::Customer() {
	arrive_ = processtime_ = 0;
}

Customer::~Customer() {

}

// time set to a random value in the range 1 - 3
void Customer::set(long when) {
	processtime_ = std::rand() % 3 + 1;
	arrive_ = when;
}

long Customer::when() const {
	return arrive_;
}

int Customer::ptime() const {
	return processtime_;
}
