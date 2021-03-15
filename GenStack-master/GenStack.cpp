#include "GenStack.h"
#include <iostream>

using namespace std;

GenStack::GenStack() //default constructor
{
  //initialization of default values - ON THE HEAP - got to delete it
  myArray = new char[128];
  size = 128;
  top = -1;
}

GenStack::GenStack(int maxSize){
  myArray = new char[maxSize];
  size = maxSize;
  top = -1;
}

GenStack::~GenStack(){
  //research this and find out what to do
  delete myArray;
}

void GenStack::push(char d){
  //Big O(1)
  //need to do error checking, thats our job
  myArray[++top] = d;
}

char GenStack::pop(){
  //error checking, make sure its not isEmpty
  return myArray[top--];
}

char GenStack::peek(){
  //check if empty
  return myArray[top];
}

bool GenStack::isFull(){
  return (top == size-1);
}

bool GenStack::isEmpty(){
  return (top == -1);
}
