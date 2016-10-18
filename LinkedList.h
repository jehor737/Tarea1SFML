/*
Jesús Horacio Rojas Cortés A01020026
Linked List class
Insert methods implemented:
    -InsertHead
    -InsertTail
    -InsertAtPosition

Delete methods implemented:
    -DeleteHead
    -RemoveHead
    -RemoveTail

Search methods implemented:
    -GetDataAtHead
    -GetDataAtTail
    -GetDataAtPosition

Print methods implemented:
    -PrintList
*/
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdexcept>
#include "Node.h"

template <class T>
class LinkedList{
    private:
        Node<T> * head = nullptr;
        int length = 0;
    public:
        //Constructors
        LinkedList() {}
        LinkedList(Node<T> _data) { head = _data; }
        //Destructor
        ~LinkedList();
        void clear();
        //Insertion Methods
        void insertHead(T data);
        void insertHead(Node<T> * new_node);
        void insertTail(T data);
        void insertTail(Node<T> * new_node);
        void insertAtPosition(T data, int position);
        void insertAtPosition(Node<T> * new_node, int position);

        //Delete methods
        T deleteHead();
        Node<T> * removeHead();
        Node<T> * removeTail();
        Node<T> * removeItem(T data);
        Node<T> * removeFromPosition(int position);

        //Search methods
        T getDataAtHead();
        T getDataAtTail();
        T getDataAtPosition(int position);

        //Print methods
        void printList();

        //Helper methods
        int size();
        Node<T> * getHead() const { return head;}
};
//////////DESTRUCTORS///////////////////
template <class T>
LinkedList<T>::~LinkedList()
{
    //cout << "Destroying the list" <<endl;
    clear();
}

template <class T>
void LinkedList<T>::clear()
{
    Node <T> * item = head;
    while(item != nullptr)
    {
        head = item->getNext();
        delete item;
        item = head;
    }
}

////////////INSERTION METHODS//////////////////////////////
template <class T>
void LinkedList<T>::insertHead(T data)
{
    //create a new node instance with the data provided
    Node<T> * new_node = new Node<T>(data);
    insertHead(new_node);
}

template <class T>
void LinkedList<T>::insertHead(Node<T> * new_node)
{
    new_node->setNext(head);
    head = new_node;
}

template <class T>
void LinkedList<T>::insertTail(T data)
{
    Node<T> * new_node = new Node<T>(data);
    insertTail(new_node);
}

template <class T>
void LinkedList<T>::insertTail(Node<T> * new_node)
{
    if(head == nullptr)
    {
        insertHead(new_node);
    }
    else
    {
        Node<T> * item = head;
        while(item->getNext() != nullptr)
        {
            item = item->getNext();
        }
        item->setNext(new_node);
    }
}

template <class T>
void LinkedList<T>::insertAtPosition(T data, int position)
{
    Node<T> * new_node = new Node<T>(data);
    insertAtPosition(new_node, position);
}

template <class T>
void LinkedList<T>::insertAtPosition(Node<T> * new_node, int position)
{
    if(position >= 0)
    {
        if(head == nullptr || position == 0)
        {
            insertHead(new_node);//inserts at head if head is a nullptr or if position is 0
        }
        else
        {
            Node<T> * temp1 = head;
            while(--position != 0 && temp1->getNext() != nullptr)
            {
                temp1 = temp1->getNext(); //gets the value until it reaches the required position and the next node is not a nullptr
            }
            //Point the temp1 next node to a new node, if the position is bigger than the list size it will add the node at the end and become the new tail
            Node<T> * temp2 = temp1->getNext();
            //Point the node that is going to be inserted to the next node
            new_node->setNext(temp2);
            //Point the previous node to the node that is going to be inserted
            temp1->setNext(new_node);
        }
    }
    else cout << "Invalid index" << endl;
}


/////////////DELETE METHODS/////////////////////
template <class T>
T LinkedList<T>::deleteHead()
{
    T data = head->getData();
    Node<T> * item = head;
    //Update the head of the list
    head = item->getNext();
    //Free the memory for the node
    delete item;
    //Return the data only
    return data;
}

template <class T>
Node<T> * LinkedList<T>::removeHead()
{
    if(head == nullptr)
        return nullptr;
    Node<T> * item = head;
    //Update the head of the list
    head = item->getNext();
    //Disconnect the node
    item->setNext(nullptr);
    //Return the node just removed
    return item;
}

template <class T>
Node<T> * LinkedList<T>::removeTail()
{
    //Return nothing if the list is empty
    if(head == nullptr)
        return nullptr;
    //Only one element in the list
    if(head->getNext() == nullptr)
    {
        Node<T> * item = head;
        head = nullptr;
        return item;
    }
    //More than one element in the list
    Node<T> * previous = head;
    Node<T> * item = previous->getNext();
    while(item->getNext() != nullptr)
    {
        previous = item;
        item = item->getNext();
    }
    //Change the tail of the list
    previous->setNext(nullptr);

    return item;
}

/*template <class T>
Node<T> * LinkedList<T>::removeItem(T data)
{

}

template <class T>
Node<T> * LinkedList<T>::removeFromPosition(int position)
{

}*/


/////////SEARCH METHODS///////////////////////
template <class T>
T LinkedList<T>::getDataAtHead()
{
    if(head == nullptr)
    {
        cout << "List is empty" << endl;
        throw std::runtime_error("Error: Empty list");
    }
    else return head->getData();
}

template <class T>
T LinkedList<T>::getDataAtTail()
{
    if(head == nullptr)
    {
        cout << "List is empty" << endl;
        throw std::runtime_error("Error: Empty list");
    }
    else
    {
        Node<T> * item = head;
        while(item->getNext() != nullptr)
        {
            item = item->getNext();
        }
        return item->getData();
    }
}

template <class T>
T LinkedList<T>::getDataAtPosition(int position)
{
    length = size();
    if(position >= 0 && position < length)
    {
        if(head == nullptr || position == 0)
        {
            return getDataAtHead();
        }
        else
        {
            Node<T> * temp1 = head;
            while(--position != 0)
            {
                temp1 = temp1->getNext(); //gets the value until it reaches the required position and the next node is not a nullptr
            }
            temp1 = temp1->getNext();
            return temp1->getData();
        }
    }

    else if(position >= 0 && position >= length)
    {
        cout << "The position " << position << " doesn't exist, but this program can show you the tail of the list" <<endl;
        return getDataAtTail();
    }

    else
    {
        cout << "The position " << position << " doesn't exist, but this program can show you the head of the list" <<endl;
        return getDataAtHead();
    }
}


/////////PRINT METHODS///////////////////////

template <class T>
void LinkedList<T>::printList()
{
    Node<T> * item = head;

    std::cout << "[ ";
    while(item != nullptr)
    {
        std::cout << item->getData() << " ";
        item = item->getNext();
    }
    std::cout << " ]" <<std::endl;
}

/////////HELPER METHODS///////////////////
template <class T>
int LinkedList<T>::size()
{
    int counter = 0; /* counter */
    Node<T> * countNode = head;
    /* traverse the list */
    while (countNode != nullptr) {
        /* Update the counter */
        counter++;
        /* move along to the next node */
        countNode = countNode->getNext();
    }
    return counter;
}
#endif
