#pragma once 
#include "Node.h"

template<class T>
class DoubleLinkedList
{
   private:
	Node<T>* Head;	//Pointer to the head of the list	
public:


	DoubleLinkedList()
	{
		Head = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~DoubleLinkedList()
	{
		DeleteAll();
	}

	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintListForward()	const
	{
		cout << "\nprinting list contents:\n\n";
		Node<T>* p = Head;

		while (p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "*\n";
	}

	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	*
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		R->setNext(Head);
        R->setPrev(nullptr);
        if (Head != nullptr)
            Head->setPrev(R);
		Head = R;
	}

	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T>* P = Head;
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
	//inserts a new node at end of the list

	void InsertEnd(const T&data) {

		Node<T>* newnode = new Node<T>;
		newnode->setNext(nullptr);
        newnode->setPrev(nullptr);
		newnode->setItem(data);
		if (Head == nullptr) {
			InsertBeg(T &data)
			return;
		}

		Node<T>* p = Head;

		while (p->getNext())
		{  
			p = p->getNext();
		}

		p->setNext()=newnode;
        newnode->setPrev()=p;

	}

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.

	Node* Find(T key) {
		Node<T>* temp = new Node<T>;
		temp = Head;
		while (temp->getNext() != nullptr)
		{
			if (temp->getItem() == key) {
				return true;
			}
			temp = temp->setNext();
		}
		return false;
	}

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list

	int CountOccurance(T value) {
		int count = 0;
		Node<T>* counter = new Node<T>;
		counter = Head;
		while (counter->getNext() != nullptr)
		{
			if (counter->getItem() == value) {
				count++;
			}
		}
		return count;
	}

	//[4] Prints list
	//Deletes the first node in the list

	void RecPrint(Node<T>* ptr) {
		ptr = Head;
		if (ptr == nullptr) {
			cout << "list is empty";
		}
		while (ptr->getNext() != nullptr)
		{
			cout << ptr;
		}
	}



	//[5] DeleteNodeVal
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
    bool DeleteNodeVal(T value) {
        Node<T>* temp = new Node<T>;
		temp = Head;
		while (temp->getNext() != nullptr)
		{
			if (temp->getItem() == key) 
            {   
                /* If node to be deleted is head node */
                if(Head == temp)
                    Head = temp->getNext();

                /* Change next only if node to be  
                 deleted is NOT the last node */
                if(temp->getNext() != nullptr)
				    temp->getnext()->setPrev()=temp->getPrev();

                /* Change prev only if node to be  
                deleted is NOT the first node */
                if(temp->getPrev() != nullptr)
                    temo->getPrev()->setNext()=temp->getPrev();


                delete temp;
                return true;
			}
			temp = temp->setNext();
		}
        return false;
	}







	//[6] DeleteNodeInd
	//deletes node with the Index (if found) and returns true
	//if not found, returns false
    bool DeleteNodeInd(T Ind) {
        Node<T>* temp = new Node<T>;
		temp = Head;
        int loop = 0; // loop counter to compare with IND
		while (temp->getNext() != nullptr && Ind>loop)
		{
			if (Ind == (loop-1)) 
            {   
                /* If node to be deleted is head node */
                if(Head == temp)
                    Head = temp->getNext();

                /* Change next only if node to be  
                 deleted is NOT the last node */
                if(temp->getNext() != nullptr)
				    temp->getnext()->setPrev()=temp->getPrev();

                /* Change prev only if node to be  
                deleted is NOT the first node */
                if(temp->getPrev() != nullptr)
                    temo->getPrev()->setNext()=temp->getPrev();


                delete temp;
                return true;
			}
			temp = temp->setNext();
            loop++;
		}
        return false;
	}



	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)

	void Reverse() 
    {

	

	    Node* reverseLinkedList(Node* Head) {
		    Node* prev = nullptr;
		    Node* current = Head;
		    Node* nextNode = nullptr;

		    while (current != nullptr) {
			    nextNode = current->next; // Save the next node
			    current->next = prev;      // Reverse the link

			    // Move to the next pair of nodes
			    prev = current;
			    current = nextNode;
		    }

		    // 'prev' now points to the new head of the reversed list
		    return prev;
	    }
    }



	
	// function to find amd return a node from linked list.
	Passenger<T> *FindPassenger(const T &key)
	{
		Node<T> *current = head;
		while (current->getNext() != nullptr)
		{
			if (*(current->data) == key)
			{
				return current;
			}
			current = current->next;
		}
		return nullptr;
	}

};