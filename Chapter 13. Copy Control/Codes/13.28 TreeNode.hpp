#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <string>

class TreeNode {
 public:
  TreeNode() : value(std::string()), count(new int(1)), left(nullptr), right(nullptr) {}

  TreeNode(const TreeNode& anotherTreeNode) : value(anotherTreeNode.value), count (anotherTreeNode.count),
  left (anotherTreeNode.left), right (anotherTreeNode.right) { ++(*this ->count);}

  TreeNode& operator= (const TreeNode&);

  ~TreeNode();

 private:
  std::string value;
  int* count;
  TreeNode *left;
  TreeNode *right;
};

#endif
