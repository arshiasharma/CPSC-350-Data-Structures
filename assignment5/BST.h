#include "TreeNode.cpp"
#include <iostream>

using namespace std;

template <class T>

class BST{
  private:
    TreeNode<T> *root;

  public:
    BST(); //default
    ~BST(); //destructor

    void recPrint(TreeNode<T>* node); //prints out info of node
    void printTree(); //printing all contents of the tree
    TreeNode<T>* getMax(); //get the node of the highest key
    TreeNode<T>* getMin(); //get the node of the minimum key value
    void insert(int key, T *data); //inserting node to the tree
    T* search(int key); //searching for the node with the int value

    bool deleteNode(int key); //deleting the node given the key
    TreeNode<T>* getSuccessor(TreeNode<T> *d); //getting the successor of the node
    void serializationMain(TreeNode<T>* node, string f); //serializing to the file
    void serialization(string f); //serializing the root node
    bool isEmpty(); //checks if the tree is empty

  };
