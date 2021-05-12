#include "BinStrTree.hpp"

BinStrTree::~BinStrTree() {
    delete this -> root;
    this -> root = nullptr;
}

BinStrTree& BinStrTree::operator=(const BinStrTree& anotherTree) {
    TreeNode* newNode = new TreeNode(*(anotherTree.root));
    delete this -> root;
    this -> root = newNode;

    return *this;
}
