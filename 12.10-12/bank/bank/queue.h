// queue.h
// interface for a queue

#pragma once

// This queue will contain Customer items

class Customer
{
public:
	Customer();
	~Customer();

	void set(long when);
	long when() const;
	int ptime() const;

private:
	long arrive_;                    // arrival time for customer
	int processtime_;                // processing time for customer
};

typedef Customer Item;

class Queue
{
public:
	Queue(int qs = Q_SIZE);          // create queue with a qs limit
	~Queue();

	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item);  // add item to end
	bool dequeue(Item& item);        // remove item from front

private:
	// class scope definitions
	// Node is a nested structure definition local to this class
	struct Node
	{
		Item item;
		struct Node* next;
	};
	enum { Q_SIZE = 10 };
	// private class members
	Node* front_;                    // pointer to front of Queue
	Node* rear_;                     // pointer to rear of Queue
	int items_;                      // current number of items in Queue
	const int qsize;                 // maximum number of items in Queue
	// preemptive definitions to prevent public copying
	Queue(const Queue& q);
	Queue& operator=(const Queue& q);
};
