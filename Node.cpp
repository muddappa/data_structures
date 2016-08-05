#include <Node.hh>

Node::Node(int d, Node *l, Node *r) {
    this->data = d;
    this->left = l;
    this->right = r;
}

