#include "GenQueue.h"
#include <iostream>

//LINKED BASED QUEUE

using namespace std;

//default constructor
template <class T>
GenQueue<T>::GenQueue(){
  myQueue = new GenDoublyLinkedList<T>();
  front = 0;
  rear = -1;
  numElements = 0;
}

//overload constructor
template<class T>
GenQueue<T>::GenQueue(int maxSize){
  myQueue = new GenDoublyLinkedList<T>();
  front = 0;
  rear = -1;
  numElements = 0;
}

//destructor
template<class T>
GenQueue<T>::~GenQueue(){
  delete [] myQueue;
}

//inserting element into the queue
template<class T>
void GenQueue<T>::insert(T *d){

  myQueue->insertBack(d);
  numElements++;
}

//removing element from the queue
template<class T>
T* GenQueue<T>::remove(){

  numElements--;
  return myQueue->removeFront();
}

//returning the first element in the queue but does not remove
template<class T>
T* GenQueue<T>::peek(){
  return myQueue->peek();
}

//returns is the queue is empty
template<class T>
bool GenQueue<T>::isEmpty(){
  if(numElements == 0){
    return true;
  }else{
    return false;
  }
}

//returns the size of the queue
template<class T>
int GenQueue<T>::getSize(){
  return numElements;
}
