#ifndef __BINARYTREE_HH
# define __BINARYTREE_HH

#include <iostream>
#include <Node.hh>
using namespace std;

class BinaryTree {
    protected:
        Node *root;
        void inOrderUtil(Node *r);
        void preOrderUtil(Node *r);
        void postOrderUtil(Node *r);
        void destroy(Node *r);
    public:
        BinaryTree();
        BinaryTree(Node *r);
        ~BinaryTree();
        void inOrder();
        void preOrder();
        void postOrder();
        void destroy();
};

#endif
