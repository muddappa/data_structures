#include <BinaryTree.hh>

BinaryTree::BinaryTree() {
    this->root = NULL;
}
   
BinaryTree::BinaryTree(Node *r) {
    this->root = r;
}
   
void BinaryTree::inOrderUtil(Node *r) {
    if (r == NULL) return;
    inOrderUtil(r->left);
    cout << r->data << "\t";
    inOrderUtil(r->right);
}

void BinaryTree::inOrder() {
    inOrderUtil(this->root);
}

void BinaryTree::preOrderUtil(Node *r) {
    if (!r) return;
    cout << r->data << "\t";
    preOrderUtil(r->left);
    preOrderUtil(r->right);
}

void BinaryTree::preOrder() {
    preOrderUtil(this->root);
}

void BinaryTree::postOrderUtil(Node *r) {
    if (!r) return;
    postOrderUtil(r->left);
    postOrderUtil(r->right);
    cout << r->data << "\t";
}

void BinaryTree::postOrder() {
    postOrderUtil(this->root);
}

void BinaryTree::destroy() {
    destroy(root);
}

void BinaryTree::destroy(Node* r) {
    if (!r) return;
    destroy(r->left);
    destroy(r->right);
    delete r;
}

bool BinaryTree::isLeaf(Node *r) {
    return (r && r->left == NULL and r->right == NULL);
}
