#include <iostream>

class GenLinkedList{
  private:
    ListNode *front;
    unsigned int size;

  public:
    GenLinkedList();
    ~GenLinkedList();

    void insertFront(int d);
    int removeFront();
    int deletePos(int pos);
    int find(int d);

    bool isEmpty();
    void printList();
    unsigned int getSize();
};
