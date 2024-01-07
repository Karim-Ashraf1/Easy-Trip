#pragma once
#include "Node.h"
#include "QueueADT.h"

template <typename T>
class PriorityQueue : public QueueADT<T>
{
private:
	Node<T> *backPtr;
	Node<T> *frontPtr;
	int priority;

public:
	PriorityQueue();
	bool isEmpty() const;
	void setPriority(int entry);
	bool enqueue(const T &newEntry) override;
	bool priorityEnqueue(const T &newEntry);
	int getPriority(const T &entry) const;
	int getSize() const;
	T dequeue();
	T peek() const;
	Node<T> *getFrontPtr() const;
	~PriorityQueue();
};

template <typename T>
const Node<T> *getFrontPtr()
{
	return frontPtr;
}

/*
Function: Queue()
The constructor of the PriorityQueue class.

*/

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;
}
/////////////////////////////////////////////////////////////////////////////////////////

/*Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/

template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:prioritiy-enqueue
Adds newEntry in the queue accourding to its priority.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool PriorityQueue<T>::priorityEnqueue(const T &newEntry)
{
	Node<T> *newNodePtr = new Node<T>(newEntry);

	int priority = getPriority(newEntry);

	if (isEmpty())
	{
		frontPtr = newNodePtr;
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
			currentPtr = currentPtr->getNext();
		}

		newNodePtr->setNext(currentPtr->getNext());
		currentPtr->setNext(newNodePtr);

		if (newNodePtr->getNext() == nullptr)
		{
			backPtr = newNodePtr;
		}
	}

	return true;
}

template <typename T>
int PriorityQueue<T>::getSize() const
{
	int count = 0;
	Node<T> *current = frontPtr;

	while (current != nullptr)
	{
		count++;
		current = current->getNext();
	}
	return count;
}

/*Function:getPriority
checks the input priority.

Input: newEntry .
Output: int shows the priority of the input.
*/

template <typename T>
int PriorityQueue<T>::getPriority(const T &entry) const
{
	return priority(entry);
}
template <typename T>
void PriorityQueue<T>::setPriority(int entry)
{
	priority=entry;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
T PriorityQueue<T>::dequeue()
{
	if (isEmpty())
		return nullptr;

	Node<T> *nodeToDeletePtr = frontPtr;
	T frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr) // Special case: last node in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;

	return frntEntry;
}

/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peek
copies the front of this queue to the passed param. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
*/

template <typename T>
T PriorityQueue<T>::peek() const
{
	if (isEmpty())
		return nullptr;

	return frontPtr->getItem();
}

///////////////////////////////////////////////////////////////////////////////////

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
	// Note that the cout statements here is just for learning purpose
	// They should be normally removed from the destructor
	cout << "\nStarting PriorityQueue destructor...";
	cout << "\nFreeing all nodes in the queue...";

	// Free all nodes in the queue
	T temp;
	while (dequeue(temp))
		;

	cout << "\n Is PrioreityQueue Empty now?? ==> " << boolalpha << isEmpty();
	cout << "\nEnding PrioretyQueue destructor..." << endl;
}