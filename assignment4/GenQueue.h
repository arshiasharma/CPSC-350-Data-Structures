#include "GenDoublyLinkedList.cpp"
#include <iostream>
using namespace std;

template <class T>

class GenQueue{
  public:
    GenQueue(); //default constructor
    GenQueue(int maxSize); //overload constructor
    ~GenQueue(); //destructor

    //core functions
    void insert(T *d); //inserts element to queue to the back
    T* remove(); //removes element from the front

    //aux functions
    T* peek(); //returns the element in the front
    bool isEmpty(); //returns if the queue is empty
    int getSize(); //returns size of the queue

    //var
    int front; //aka front
    int rear; //aka tail
    int numElements; //number of elements in the queue

    GenDoublyLinkedList<T> *myQueue; //queue 
};
