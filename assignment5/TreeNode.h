#include <iostream>
using namespace std;

template <class T>

class TreeNode{
  public:
    TreeNode(); //default constructor
    TreeNode(int k, T *d); // k = key -> overload constructor
    ~TreeNode(); //destructor

    //member variables 
    int key;
    T *data;
    TreeNode *left;
    TreeNode *right;
};
