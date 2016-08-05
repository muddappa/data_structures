#include <BinarySearchTree.hh>

void BinarySearchTree::insert(int value, Node*& r) {
    if (!r) {
        r = new Node(value, NULL, NULL);
    }
    if (value < r->data)
        insert(value, r->left);
    if (value > r->data)
        insert(value, r->right);
}

void BinarySearchTree::insert(int value) {
    insert(value, root);
}

Node* BinarySearchTree::search(int value, Node *r) {
    if (!r) return NULL;
    if (r->data == value) return r;
    if (value < r->data) return search(value, r->left);
    if (value > r->data) return search(value, r->right);
}

Node* BinarySearchTree::search(int value) {
    return search(value, root);
}

