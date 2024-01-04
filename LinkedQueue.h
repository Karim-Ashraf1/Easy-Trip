
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
	bool dequeue(T &frntEntry);
	Node<T>* peek() const;
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
Node<T>* LinkedQueue<T>::peek() const
{
    return frontPtr;
}



///////////////////////////////////////////////////////////////////////////////////

/*
Function: PrintQueue
Print the queue elements.

Input: None.
Output: elements of the queue.
*/

//template <typename T>
//void PrintQueue() {
//	Node<T> *temp = new Node<T>;
//	temp = frontPtr;
  //  while (!isEmpty()) {
 //       cout << temp->getItem();
	//	temp = temp->getNext();
   // }

//}

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