#include "GenQueue.h"
#include <iostream>

using namespace std;

GenQueue::GenQueue(){
  //default constructor
  myQueue = new char[128];
  size = 0;
  front = 0;
  rear = -1;
  numElements = 0;
}

GenQueue::GenQueue(int maxSize){
  myQueue = new char[maxSize];
  size = maxSize;
  front = 0;
  rear = -1;
  numElements = 0;

}

GenQueue::~GenQueue(){
  delete myQueue;
}

void GenQueue::insert(char d){
  //add error checking - 2 lines
  myQueue[++rear] = d;
  ++numElements;
}

char GenQueue::remove(){
  //error checking
  char c = '\0';
  c = myQueue[front];
  ++front;
  --numElements;
  return c;
}

char GenQueue::peek(){
  return myQueue[front];
}

bool GenQueue::isFull(){
  return (numElements == size);
}

bool GenQueue::isEmpty(){
  return (numElements == 0);
}

int GenQueue::getSize(){
  return numElements;
}
