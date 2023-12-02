#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#include "Node.h"
#include "QueueADT.h"

template <typename T>
class LinkedQueue : public QueueADT<T>
{
private:
	Node<T> *backPtr;
	Node<T> *frontPtr;

public:
	LinkedQueue();
	bool isEmpty() const;
	bool enqueue(const T &newEntry);
	bool priorityEnqueue(const T &newEntry);
	int getPriority(const T &entry) const;
	bool dequeue(T &frntEntry);
	bool peek(T &frntEntry) const;
	~LinkedQueue();
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/

template <typename T>
LinkedQueue<T>::LinkedQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;
}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool LinkedQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool LinkedQueue<T>::enqueue(const T &newEntry)
{
	Node<T> *newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (isEmpty())			   // special case if this is the first node to insert
		frontPtr = newNodePtr; // The queue is empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty

	backPtr = newNodePtr; // New node is the last node now
	return true;
} // end enqueue

/////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function:prioritiy-enqueue
Adds newEntry in the queue accourding to its priority.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

// this code is made by the leader "karim";
template <typename T>
bool LinkedQueue<T>::priorityEnqueue(const T &newEntry)
{
	Node<T> *newNodePtr = new Node<T>(newEntry);

	int priority = getPriority(newEntry);

	if (isEmpty())
	{
		frontPtr = newNodePtr; // kariiiiim
		backPtr = newNodePtr;
		return true;
	}

	if (priority > getPriority(frontPtr->getItem()))
	{
		newNodePtr->setNext(frontPtr);
		frontPtr = newNodePtr;
	}
	else
	{
		Node<T> *currentPtr = frontPtr;
		while (currentPtr->getNext() != nullptr && priority <= getPriority(currentPtr->getNext()->getItem()))
		{
			currentPtr = currentPtr->getNext(); // leaderrrr
		}

		newNodePtr->setNext(currentPtr->getNext());
		currentPtr->setNext(newNodePtr);

		if (newNodePtr->getNext() == nullptr)
		{
			backPtr = newNodePtr; // kariiim is the leaderrrr
		}
	}

	return true;
}

/*Function:getPriority
checks the input priority.

Input: newEntry .
Output: int shows the priority of the input.
*/

template <typename T>
int LinkedQueue<T>::getPriority(const T &entry) const
{
	if (entry == "SP")
	{ // karim is the highest priority of course
		return 3;
	}
	else if (entry == "WP")
	{ // nour is the secound
		return 2;
	}
	else if (entry == "NP")
	{ // taha is the third
		return 1;
	}
	else
	{ // faris is not a priority
		return 0;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool LinkedQueue<T>::dequeue(T &frntEntry)
{
	if (isEmpty())
		return false;

	Node<T> *nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr) // Special case: last node in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;

	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peek
copies the front of this queue to the passed param. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
*/

template <typename T>
bool LinkedQueue<T>::peek(T &frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;
}
///////////////////////////////////////////////////////////////////////////////////

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
	// Note that the cout statements here is just for learning purpose
	// They should be normally removed from the destructor
	cout << "\nStarting LinkedQueue destructor...";
	cout << "\nFreeing all nodes in the queue...";

	// Free all nodes in the queue
	T temp;
	while (dequeue(temp))
		;

	cout << "\n Is LinkedQueue Empty now?? ==> " << boolalpha << isEmpty();
	cout << "\nEnding LinkedQueue destructor..." << endl;
}

#endif