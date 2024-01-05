#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include <iostream>
using namespace std;

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
    Node<T> *GetHead()
    {
        return Head;
    }
    // List is being desturcted ==> delete all items in the list
    ~LinkedList()
    {
        DeleteAll();
    }

    // prints the values of all nodes in a linked list.

    void PrintList() const
    {
        cout << "\nprinting list contents:\n\n";
        Node<T> *p = Head;

        while (p)
        {
            cout << "[ " << p->getItem() << " ]";
            cout << "--->";
            p = p->getNext();
        }
        cout << "*\n";
    }

    // Creates a new node and adds it to the beginning of a linked list.
    void InsertBeg(const T &data)
    {
        Node<T> *R = new Node<T>(data);
        R->setNext(Head);
        Head = R;
    }

    // Deletes all nodes of the list.
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

    bool IsEmpty() const
    {
        return Head == nullptr;
    }

    // [1]InsertEnd
    // inserts a new node at end if the list
    void InsertEnd(T value)
    {
        Node<T> *temp = Head;
        Node<T> *next = new Node<T>(value);
        while (temp->getNext() != nullptr)
        {
            temp = temp->getNext();
        }
        temp->setNext(next);
        next->setNext(nullptr);
    }

    //[2]Find
    // searches for a given value in the list, returns true if found; false otherwise.

    bool Find(T key)
    {
        Node<T> *curr_node = Head;
        while (curr_node != nullptr)
        {
            if (curr_node->getItem() == key)
                return true;
            else
                return false;
            curr_node = curr_node->getNext();
        }
    }
    //[3]CountOccurance
    int CountOccurance(T value)
    {
        Node<T> *temp = Head;
        int count = 0;
        while (temp != NULL)
        {
            if (temp->getItem() == value)
            {
                count++;
            }
            temp = temp->getNext();
        }
        return count;
    }
    //[4] DeleteFirst
    // Deletes the first node in the list

    void DeleteFirst()
    {
        Node<T> *temp = new Node<T>;
        temp = Head;
        Head = Head->getNext();
        delete temp;
    }

    //[5] DeleteLast
    // Deletes the last node in the list
    void DeleteLast()
    {
        Node<T> *temp = Head;
        Node<T> *next = new Node<T>;
        while (temp->getNext()->getNext() != nullptr)
        {
            temp = temp->getNext();
        }
        next = temp->getNext();
        temp->setNext(nullptr);
        delete next;
    }

    bool DeleteNode(T value)
    {
        Node<T> *temp = Head;
        Node<T> *next = new Node<T>(value);
        while (temp != nullptr)
        {
            if (temp->getNext()->getItem() == value)
            {
                next = (temp->getNext());
                temp->setNext(next->getNext());
                delete next;
                return true;
            }
        }
        return false;
    }

    //[7] DeleteNodes
    // deletes ALL node with the given value (if found) and returns true
    // if not found, returns false
    // Note: List is not sorted

    bool DeleteNodes(T value)
    {
        Node<T> *temp = Head;
        bool check = false;

        while (temp->getNext() != nullptr)
        {
            if (temp->getItem() == value)
            {
                Node<T> *Delete = new Node<T>(value);
                Delete = temp;
                Head = Head->getNext();
                temp = Head;
                delete Delete;
                check = true;
            }
            else if (temp->getNext()->getItem() == value)
            {
                Node<T> *Delete = new Node<T>(value);
                Delete = temp->getNext();
                temp->setNext(temp->getNext()->getNext());
                delete Delete;
                check = true;
            }
            else
            {
                temp = temp->getNext();
            }
        }
        return check;
    }

    //[8] Reverse
    // Reverses the linked list (without allocating any new Nodes)
    void Reverse()
    {
        Node<T> *current = Head;
        Node<T> *prev = nullptr, *next = nullptr;

        while (current != nullptr)
        {
            // Store next
            next = current->getNext();
            // Reverse current node's pointer
            current->setNext(prev);
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        Head = prev;
    }
};

#endif