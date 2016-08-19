#ifndef __BINARYsEARCHTREE_HH

# define __BINARYsEARCHTREE_HH

#include <BinaryTree.hh>
#include <map>

class BinarySearchTree: public BinaryTree {
    private:
        void insert(int value, Node*& r);
        Node* search(int value, Node* r);
        Node* findMin(Node *r);
        Node* findMax(Node *r);
        Node* findParent(Node* r, int value);
        Node* deleteNode(int value, Node* r);
        void insertOnCondition(int value, Node*& r, int k);
        void findNearest(int value, Node* r, Node*& nearest);
        void findNodes(int value, Node* r, std::map<int, Node*>& nodeMap, Node*& node1, Node*& node2);
    public:
        void insert(int value);
        Node* search(int value);
        void deleteNode(int value);
        Node* find(int value);
        void insertOnCondition(int value, int k);
        Node* findNearest(int value);
        void findNodes(int value, Node*& node1, Node*& node2);
};

#endif
