#include <iostream>

using namespace std;

template <class T>

class ListNode{
  public:

    //member variables
    T data;
    ListNode *next;
    ListNode *prev;

    //constructor and destructor
    ListNode();
    ListNode(T d);
    ~ListNode();
};
