#include "ListNode.h"
#include <iostream>

using namespace std;

template <class T>
ListNode<T>::ListNode(){}

//overload constructor
template <class T>
ListNode<T>::ListNode(T *d){
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
