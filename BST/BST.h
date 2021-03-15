class BST{
private:
  TreeNode *root;

public:
  BST();
  ~BST();

  bool search(int value);
  void insert(int value);

  //delete placeholder

  //helper function
  bool isEmpty();
  TreeNode* getMin();
  TreeNode* getMax();
  void printTree();
  void recPrint(TreeNode *node);
};
