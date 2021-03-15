#include "GenLinkedList.h"
#include "ListNode.h"
#include <iostream>

GenLinkedList::GenLinkedList(){
  size = 0;
  front = NULL;
}

GenLinkedList::~GenLinkedList(){
  while (!empty()){
    delete front;
  }
}

unsigned int GenLinkedList::getSize(){
  return size;
}

void GenLinkedList::printList(){
  ListNode *curr = front;

  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}

void GenLinkedList::insertFront(int d){
  ListNode *node = newListNode(d);
  node->next = front;
  front = node;
  size++;
}

int GenLinkedList::removeFront(){
  int temp = front->data;
  ListNode *ft = front;
  front = front-> next;
  ft->next = NULL;
  delete ft;
  size--;

  return temp;
}

int GenLinkedList::deletePos(int pos){
  int idx = 0;
  ListNode *prev = front;
  ListNoed *curr = front;

  while(idx != pos){
    prev = curr;
    curr = curr->next;
    idx++;
  }

  //found the node to be deleted
  prev->next = curr->next;
  curr->next = NULL;
  int tmp = curr->data;

  delete curr;
  size--;

  return tmp;
}

int GenLinkedList::find(int d){
  int idx = 0;
  ListNode *curr = front;

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

bool GenLinkedList::isEmpty(){
  if(size == 0){
    return true;
  }
  else{
    return false;
  }
}
