#include "GenStack.h"
#include <iostream>

using namespace std;

//default constructor
template<class T>
GenStack<T>::GenStack(){
  myArray = new T[128];
  size = 128;
  top = -1;
}

//overload constructor
template<class T>
GenStack<T>::GenStack(int maxSize){
  myArray = new T[maxSize];
  size = maxSize;
  top = -1;
}

//destructor
template<class T>
GenStack<T>::~GenStack(){
  delete myArray;
}

//if the stack is full, a new stack is created with double to orginal size
template<class T>
void GenStack<T>::newStack(){
  size = size + size;
  T *newStack;
	newStack = new T[size];
	for(int i = 0; i < (size/2); i++){
		newStack[i] = myArray[i];
	}
  myArray = newStack;
}
//push element T on top of the stack
template<class T>
void GenStack<T>::push(T d){
  if(isFull()){
    cout << "Stack is full" << endl;
  }else{
    myArray[++top] = d;
  }
}

//push element T* on top of the stack (pointer object)
template<class T>
void GenStack<T>::push2(T *d){
  if(isFull()){
    cout << "Stack is full" << endl;
  }else{
    myArray[++top] = *d;
  }
}

//removing top element from the top of the stack
template<class T>
T GenStack<T>::pop(){
  if(isEmpty()){
    cout <<"Stack is empty" << endl;
  }else{
    return myArray[top--];
  }
}

//removing top element pointer from the top of the stack
template<class T>
T* GenStack<T>::pop2(){
  if(isEmpty()){
    cout <<"Stack is empty" << endl;
  }else{
    T* temp = &myArray[top];
    return temp;
  }
}

//returning first element (on top of the stack)
template<class T>
T GenStack<T>::peek(){
  if(isEmpty()){
    cout <<"Stack is empty" << endl;
  }else{
    return myArray[top];
  }
}

//returns if true or false
template<class T>
bool GenStack<T>::isFull(){
  return(top == size-1);
}

//returns of true of false
template<class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}
