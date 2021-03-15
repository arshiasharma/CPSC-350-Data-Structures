#include "ListNode.h"

class GenDoublyLinkedList{
  private:
    ListNode *front;
    ListNode *back;
    unsigned int size;

  public:
    GenDoublyLinkedList();
    ~GenDoublyLinkedList();

    void insertFront(int d);
    void insertBack(int d);
    int removeFront();
    int removeBack();
    int deletePos(int pos);
    int find(int d);

    bool isEmpty();
    void printList();
    unsigned int getSize();
};
