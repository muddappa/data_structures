#ifndef _NODE_HH
# define _NODE_HH

#include <iostream>
using namespace std;

struct Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d, Node *l, Node *r);
};

#endif
