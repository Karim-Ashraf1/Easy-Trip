#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include <iostream>

template <typename T>
class LinkedList
{
private:
	Node<T> *Head; // Pointer to the head of the list
	// You can add tail pointer too (depending on your problem)
public:
	LinkedList()
	{
		Head = nullptr;
	}

	// List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}

	/*
	 * Function: PrintList.
	 * prints the values of all nodes in a linked list.
	 */
	void PrintList() const
	{
		std::cout << "\nprinting list contents:\n\n";
		Node<T> *p = Head;

		while (p)
		{
			std::cout << "[ " << p->getItem() << " ]";
			std::cout << "--->";
			p = p->getNext();
		}
		std::cout << "*\n";
	}

	/*
	 * Function: InsertBeg.
	 * Creates a new node and adds it to the beginning of a linked list.
	 *
	 * Parameters:
	 *	- data : The value to be stored in the new node.
	 */
	void InsertBeg(const T &data)
	{
		Node<T> *R = new Node<T>(data);
		R->setNext(Head);
		Head = R;
	}

	/*
	 * Function: DeleteAll.
	 * Deletes all nodes of the list.
	 */
	void DeleteAll()
	{
		Node<T> *P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}

	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions

	//[1]InsertEnd
	// inserts a new node at end if the list

	void InsertEnd(const T &data)
	{

		Node<T> *newnode = new Node<T>;
		newnode->setNext(nullptr);
		newnode->setItem(data);
		if (Head == nullptr)
		{
			Head = newnode;
			return;
		}

		Node<T> *p = Head;

		while (p->getNext())
		{
			p = p->getNext();
		}

		p->setNext();
	}

	//[2]Find
	// searches for a given value in the list, returns true if found; false otherwise.

	Passenger *Find(T key)
	{
		Node<T> *temp = new Node<T>;
		temp = Head;
		while (temp->getNext() != nullptr)
		{
			if (temp->getItem() == key)
			{
				return temp;
			}
			temp = temp->setNext();
		}
	}

	//[3]CountOccurance
	// returns how many times a certain value appeared in the list

	int CountOccurance(T value)
	{
		int count = 0;
		Node<T> *counter = new Node<T>;
		counter = Head;
		while (counter->getNext() != nullptr)
		{
			if (counter->getItem() == value)
			{
				count++;
			}
		}
		return count;
	}

	//[4] DeleteFirst
	// Deletes the first node in the list

	void RecPrint(Node<T> *ptr)
	{
		ptr = Head;
		if (ptr == nullptr)
		{
			std::cout << "list is empty";
		}
		while (ptr->getNext() != nullptr)
		{
			std::cout << ptr;
		}
	}

	//[5] DeleteLast
	// Deletes the last node in the list

	void DeleteFirst()
	{
		Node<T> *first = new Node<T>;
		first = Head->getNext();
		delete Head;
	}

	//[6] DeleteNode
	// deletes the first node with the given value (if found) and returns true
	// if not found, returns false
	// Note: List is not sorted

	void DeleteLast()
	{
		Node<T> *last = new Node<T>;
		while (last->getNext() != nullptr)
		{
			if (last->getNext() == nullptr)
			{
				delete last;
			}
		}
	}

	//[7] DeleteNodes
	// deletes ALL node with the given value (if found) and returns true
	// if not found, returns false
	// Note: List is not sorted

	bool DeleteNode(T value)
	{
	}

	bool DeleteNodes(T value)
	{
	}

	//[8]Merge
	// Merges the current list to another list L by making the last Node in the current list
	// point to the first Node in list L

	void Merge(LinkedList<T> L)
	{
		Node<T> *merge = new Node<T>;
		merge = Head;
		while (merge->getNext() != nullptr)
		{
			if (merge->getItem() == nullptr)
			{
			}
		}
	}

	//[9] Reverse
	// Reverses the linked list (without allocating any new Nodes)

	void Reverse()
	{

		Node *reverseLinkedList(Node * Head)
		{
			Node *prev = nullptr;
			Node *current = Head;
			Node *nextNode = nullptr;

			while (current != nullptr)
			{
				nextNode = current->next; // Save the next node
				current->next = prev;	  // Reverse the link

				// Move to the next pair of nodes
				prev = current;
				current = nextNode;
			}

			// 'prev' now points to the new head of the reversed list
			return prev;
		}
	}
};

#endif