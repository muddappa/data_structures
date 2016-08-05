#ifndef __BINARYsEARCHTREE_HH

# define __BINARYsEARCHTREE_HH

#include <BinaryTree.hh>

class BinarySearchTree: public BinaryTree {
    private:
        void insert(int value, Node*& r);
        Node* search(int value, Node* r);
    public:
        void insert(int value);
        Node* search(int value);
        //Node* deleteNode(int value);
};

#endif
