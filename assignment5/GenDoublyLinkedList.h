#include "ListNode.cpp"
#include <iostream>

using namespace std;

template <class T> 

class GenDoublyLinkedList{
  private:
    ListNode<T> *front; //pointer to the node in the front
    ListNode<T> *back; //pointer to the node in the back
    unsigned int size; //size of the DoublyLinkedList

  public:
    GenDoublyLinkedList(); //constructor
    ~GenDoublyLinkedList(); //destructor

    void insertFront(T d); //insert node to front
    void insertBack(T d); //insert node to back
    T removeFront(); //removes and returns node in the front
    T removeBack(); //removes and returns node in the back
    T peek(); //returns the node in the front
    T deletePos(T pos); //delete and returns node at certain position
    int find(T d); //finds and returns the position of a node

    bool isEmpty(); //checks if list is empty
    void printList(); //prints the list
    string returnList(); //returns list
    unsigned int getSize(); //returns the size of list
};
