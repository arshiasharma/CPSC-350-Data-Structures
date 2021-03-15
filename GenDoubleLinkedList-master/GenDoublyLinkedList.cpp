#include "GenDoublyLinkedList.h"

GenDoublyLinkedList::GenDoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

GenDoublyLinkedList::~GenDoublyLinkedList(){
  //iterate through the list
}

void GenDoublyLinkedList::insertFront(int d){
  ListNode *node = newListNode(d);

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

int GenDoublyLinkedList::removeFront(){
  //check if empty
  ListNode *ft = front;

  if(front->next == NULL){
    //only one element in the list
    back = NULL;
  }else{
    //more than one element in the list
    front->next->prev = NULL;
  }
  front = front->next;
  int temp = ft->data;
  ft->next = NULL;
  delete ft;
  size--;

  return temp;
}

void GenDoublyLinkedList::insertBack(int d){
  ListNode *node = new ListNode(d);

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

ListNode* GenDoublyLinkedList::removeBack(int d){
  ListNode *bk = back;
  
  if(back->prev == NULL){
    front = bk;
  }
  
  else{
    back->prev->next = NULL;
  }
  int temp = bk->data;
  back = back->prev;
  bk->prev = NULL;
  delete bk;
  size--;
  
  return temp;

}

ListNode* GenDoublyLinkedList::remove(int d){
  //check if empty before attempting to remove node

  ListNode *curr = front;

  while(curr->data != d){
    curr = curr->next;

    if(curr == NULL){
      return NULL;
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
      curr->next->prev curr->prev;
    }

    curr->next = NULL;
    curr->prev = NULL;
    size--;

    return curr;
  }
}
