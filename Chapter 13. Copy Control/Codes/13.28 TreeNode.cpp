#include "TreeNode.hpp"

TreeNode& TreeNode::operator=(const TreeNode& anotherTreeNode) {
    ++(*anotherTreeNode.count);

    // Same as destructor part here.
    if (--(*this -> count) == 0) {
        delete this -> count;
        this -> count = nullptr;
        if (this -> left) {
            delete this -> left;
            this -> left = nullptr;
        }
        if (this -> right) {
            delete this -> right;
            this -> right = nullptr;
        }
    }

    // Same as copy constructor part.
    this -> value = anotherTreeNode.value;
    this -> count = anotherTreeNode.count;
    this -> left = anotherTreeNode.left;
    this ->  right = anotherTreeNode.right;
     ++(*this -> count);

    return *this;
}

TreeNode::~TreeNode() {
    if (--(*this -> count) == 0) {
        delete this -> count;
        this -> count = nullptr;
        if (this -> left) {
            delete this -> left;
            this -> left = nullptr;
        }
        if (this -> right) {
            delete this -> right;
            this -> right = nullptr;
        }
    }
}
