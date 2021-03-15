#include "ListNode.h"
#include <iostream>

ListNode::ListNode(){
  data = -1;
}

ListNode::ListNode(int d){
  data = d;
  next = NULL; //null pointer
}

ListNode::~ListNode(){
  if(next == NULL){
    delete next;
  }
}
