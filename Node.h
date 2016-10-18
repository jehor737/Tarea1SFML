/*
Node class for use in Linked lists and similar structures
Jesús Horacio Rojas Cortés A01020026
14/09/2016
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <class T>
class Node{
    private:
        T data;
        Node * next = nullptr;
        
    public:
      Node() {}
      Node(T _data){ data = _data; }
      ~Node() {next = nullptr; }
      
      void setData(T _data) { data = _data; }
      void setNext(Node * _next) { next = _next; }
      T getData() { return data; }
      Node * getNext() { return next; }
      template<class S>
      friend std::ostream & operator<< (std::ostream & stream, const Node<S> & node);
};

template <class T>
std::ostream & operator<< (std::ostream & stream, const Node<T> & node)
{
    stream << "-" << node.data << "-";
    return stream;
}


#endif