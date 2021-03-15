class TreeNode{
public:
  TreeNode();
  TreeNode(int k) // k = key, which is also value(data)
  ~TreeNode();

  int key;
  TreeNode *left;
  TreeNode *right;
};
