ListNode::ListNode(){}

ListNode::ListNode(int d){
  data = d;
  next = NULL;
  prev = NULL;
}

ListNode::~ListNode(){
  next = NULL;
  prev = NULL;
}
