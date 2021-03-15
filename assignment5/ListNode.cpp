#include "ListNode.h"
#include <iostream>

using namespace std;

//default constructor
template <class T>
ListNode<T>::ListNode(){
  data = NULL;
  next = NULL;
  prev = NULL;
}

//overload constructor
template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

//destructor
template <class T>
ListNode<T>::~ListNode(){
  next = NULL;
  prev = NULL;
}
