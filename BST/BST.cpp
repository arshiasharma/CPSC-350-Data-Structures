#include "BST.h"

//RED BLACK TREES
//Tree node changes
//insert and delete changes
BST::BST(){
  root = NULL; //empty tree
}

BST::~BST(){
  //character building
}

void BST::recPrint(TreeNode *node){
  if(node == NULL){
    return;
  }

  //inorder traversal
  recPrint(node->left);
  cout << node->key << endl;
  recPrint(node->right);

  /* preorder
  cout << node->key << endl;
  recPrint(node->left);
  recPrint(node->right);

  postorder
  recPrint(node->left);
  recPrint(node->right);
  cout << node->key << endl;
  */
}

void BST::printTree(){
  recPrint(root);
}

TreeNode* BST::getMax(){
  TreeNode *current = root;

  if(root == NULL){ //empty tree
    return NULL;
  }

  while(current->right != NULL){
    current = current->right;
  }
  return current;
}

TreeNode* BST::getMin(){
  //oppostion of getMin
  TreeNode *current
}

void BST::insert(int value){
  TreeNode *node = new TreeNode(value);

  if(root == NULL){
    root = node;
  }

  else{
    TreeNode *current = root;
    TreeNode *parent = NULL;

    while(true){
      parent = current;

      if(value < current->key){
        current = current->left;

        if(current == NULL){
          //we found the insertion point
          parent->left = node;
          break;
        }


      }else{
        current = current->right;

        if(current == NULL){
          //we found the insertion point
          parent->right = node;
          break;
        }
      }
    }
  }
}

bool BST::search(int value){
  if(root == NULL){
    return false;
  }

  else{
    //tree is not empty, lets find it
    TreeNode *current = root;

    while(current->key != value){
      if(value < current->key){
        current = current->left;
      }else{
        current = current->right;
      }
      if(current == NULL){ //value doesnt exist
        return false;
      }
    }
  }
  return true;
}

bool BST::deleteNode(int value){
  if(root == NULL){
    return false;
  }

  TreeNode *current = root;
  TreeNode *parent = root;
  bool isLeft = true;

  //if we make it here, the tree isnt empty so we find node

  while(current->key != value){
    parent = current;
    if(value < current->key){
      isLeft = true;
      current = current->left;
    }else{
      isLeft = false;
      current = current->right;
    }
    if(current == NULL){ //value doesnt exist
      return false;
    }

    //no children (leaf)

    if(current->left == NULL && current->right == NULL){
      if(current == root){
        root = NULL;
      }else if (isLeft){
        parent->left = NULL;
      }else{
        parent->right = NULL;
      }
    }

    //node to be deleted has one child, we need to know if child is left or right
    else if(current->right == NULL){ //doesnt have right, should be left child
      //need to check if its a root
      if(current == root){
        root = current->left;
      }else if(isLeft){
        parent->left = current->left;
      }else{ //right child
        parent->right = current->left;
      }
    }

    else if(current->left == NULL){ //doesnt have left, should be right child
      //need to check if its a root
      if(current == root){
        root = current->right;
      }else if(isLeft){
        parent->left = current->right;
      }else{ //right child
        parent->right = current->right;
      }
    }

    else{
      //node to be deleted has 2 children so rip
      TreeNode *successor = getSuccessor(current);

      if(current == root){
        root = successor;
      }else if(isLeft){
        parent->left = successor;
      }else{
        parent->right = successor;
      }
      successor->left = current->left;
    }

    return true;
}

TreeNode* BST::getSuccessor(TreeNode *d){ //d is the node to be deleted
  TreeNode *current = d->right;
  TreeNode *sp = d;
  TreeNode *successor = d;

  while(current != NULL){
    //traverse tree until we find successor
    sp = successor;
    successor = current;
    current = current->left;
  }

  //by this point, all of our pointers such be in the right spot
  if(successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}
