#include "GenDoublyLinkedList.h"
#include <iostream>
#include <string>

//default constructor
template<class T>
GenDoublyLinkedList<T>::GenDoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

//destructor
template<class T>
GenDoublyLinkedList<T>::~GenDoublyLinkedList(){
  //iterate through the list
  while (front->next != front)
	{
		ListNode<T>* curr = front->next;
		curr->next->prev = front;
		front->next = curr->next;
		delete curr;
	}
	delete front;
}


//inserts a node to the front
template<class T>
void GenDoublyLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()){
    //the list is now empty
    back = node;
  }else{
    //not empty
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

//removes the node from the front of the list
template<class T>
T GenDoublyLinkedList<T>::removeFront(){
  T temp;
  if(isEmpty()){
    cout << "List empty" << endl;
  }else{
    ListNode<T> *ft = front;

    if(front->next == NULL){
      //only one element in the list
      back = NULL;
    }else{
      //more than one element in the list
      front->next->prev = NULL;
    }
    front = front->next;
    temp = ft->data;
    ft->next = NULL;
    delete ft;
    size--;
  }
  return temp;
}

//returns the data stored in the front but doesnt remove
template<class T>
T GenDoublyLinkedList<T>::peek(){
  if(isEmpty()){
    cout << "Linked List already empty" << endl;
  }else{
    return front->data;
  }
}

//inserts node to the back of the list
template<class T>
void GenDoublyLinkedList<T>::insertBack(T d){
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()){
    //empty list
    front = node;
  }else{
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

//removes the node at the back of the list
template<class T>
T GenDoublyLinkedList<T>::removeBack(){
  T *temp = new ListNode<T>;
  if(isEmpty()){
    cout << "List already empty" << endl;
  }else{
    ListNode<T> *bk = back;

    if(front->next == NULL){
      //only one element in the list
      front = NULL;
    }else{
      //more than one element in the list
      back->prev->next = NULL;
    }
    back = back->prev;
    temp = bk->data;
    bk->prev = NULL;
    delete bk;
    size--;

  }
  return temp;
}

//deletes node at a certain position
template<class T>
T GenDoublyLinkedList<T>::deletePos(T d){
  if(isEmpty()){
    cout << "List already empty" << endl;
  }else{
    ListNode<T> *curr = front;

    if(curr->data == d){
      front = curr->next;
      size--;
    }

    while(curr->data != d){
      curr = curr->next;

      if(curr == NULL){
        return -1;
      }
      //if we get to this point, we found the node to be removed

      if(curr == front){
        front = curr->next;
      }
      else{
      //its not the front, its in between
      curr->prev->next = curr->next;

      }if(curr == back){
        back = curr->prev;
      }else{
        curr->next->prev = curr->prev;
      }

      curr->next = NULL;
      curr->prev = NULL;
      size--;

    }
    return curr->data;
  }
}

//finds the position of a data
template<class T>
int GenDoublyLinkedList<T>::find(T d){
  if(isEmpty()){
    cout << "List already empty" << endl;
  }else{
    int idx = 0;
    ListNode<T> *curr = front;

    while(curr != NULL){
      if(curr->data == d){
        break;
      }else{
        curr = curr->next;
        idx++;
      }
    }

    if(curr == NULL){ //did not find the value we want
      idx = -1;
    }
    return idx;
  }
}

//returns if the list is empty
template<class T>
bool GenDoublyLinkedList<T>::isEmpty(){
  if(size == 0){
    return true;
  }
  else{
    return false;
  }
}

//prints list
template<class T>
void GenDoublyLinkedList<T>::printList(){
  ListNode<T> *curr = front;

  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
  if(curr == NULL){
    //cout << "No advisees" << endl;
  }
}

//returns string of the numbers in List
template <class T>
string GenDoublyLinkedList<T>::returnList(){
  ListNode<T> *curr = front;
  string temp = "\n";

  while(curr != NULL){
    temp += to_string(curr->data);
    curr = curr->next;

    if(curr != NULL){
      temp += " ";
    }
  }
  return temp;
}

//returns the size
template<class T>
unsigned int GenDoublyLinkedList<T>::getSize(){
  return size;
}
