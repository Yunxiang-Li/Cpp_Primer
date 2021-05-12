#ifndef BINSTRTREE_HPP
#define BINSTRTREE_HPP

#include "TreeNode.hpp"

class BinStrTree {
 public:
  BinStrTree() : root(new TreeNode()) {}

  BinStrTree(const BinStrTree& anotherTree) : root(new TreeNode(*(anotherTree.root))) {}

  BinStrTree& operator=(const BinStrTree&);

  ~BinStrTree();

 private:
  TreeNode *root;
};

#endif
