#include <BinarySearchTree.hh>
#include <cmath>
#include <map>

void BinarySearchTree::insert(int value, Node*& r) {
    if (!r) {
        r = new Node(value, NULL, NULL);
    }
    if (value < r->data)
        insert(value, r->left);
    if (value > r->data)
        insert(value, r->right);
}

void BinarySearchTree::insertOnCondition(int value, int k) {
    insertOnCondition(value, root, k);
}

void BinarySearchTree::insertOnCondition(int value, Node*& r, int k) {
    if (!r) r = new Node(value, NULL, NULL);
    if (abs(r->data - value) <= k)
        return;
    if (value < r->data)
        insertOnCondition(value, r->left, k);
    else if (value > r->data)
        insertOnCondition(value, r->right, k);
}

void BinarySearchTree::insert(int value) {
    insert(value, root);
}

void BinarySearchTree::findNearest(int value, Node* r, Node*& nearest) {
    if (!r) return;
    if (r->data == value) {
        nearest = r;
        return;
    }
    if (abs(r->data - value) <= abs(nearest->data - value)) nearest = r;
    if (value < r->data) findNearest(value, r->left, nearest);
    else if (value > r->data) findNearest(value, r->right, nearest);

}

Node* BinarySearchTree::findNearest(int value) {
    Node* near = new Node(root->data, NULL, NULL);
    Node* tmp = near;
    findNearest(value, root, near);
    delete tmp;
    return near;
}

void BinarySearchTree::findNodes(int value, Node* r, std::map<int, Node*>& nodeMap, Node*& node1, Node*& node2) {
    if (!r) return;
    if (node1 && node2) return;
    findNodes(value, r->left, nodeMap, node1, node2);
    std::map<int, Node*>::iterator it = nodeMap.find(value - r->data);
    if (it != nodeMap.end()) {
        node1 = it->second;
        node2 = r;
        return;
    }
    else nodeMap[r->data] = r;
    findNodes(value, r->right, nodeMap, node1, node2);
}

void BinarySearchTree::findNodes(int value, Node*& node1, Node*& node2) {
    std::map<int, Node*> nodeMap;
    findNodes(value, root, nodeMap, node1, node2);
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

Node* BinarySearchTree::findParent(Node* r, int value) {
    if (!r) return NULL;
    if (r->left && r->left->data == value || r->right && r->right->data == value) return r;
    if (value < r->data) return findParent(r->left, value);
    if (value > r->data) return findParent(r->right, value);
}

Node* BinarySearchTree::findMin(Node *r) {
    if (!r) return NULL;
    if (r->left == NULL) return r;
    return findMin(r->left);
}

Node* BinarySearchTree::findMax(Node *r) {
    if (!r) return NULL;
    if (r->right == NULL) return r;
    return findMin(r->right);
}

void BinarySearchTree::deleteNode(int value) {
    deleteNode(value, root);
}

Node* BinarySearchTree::deleteNode(int value, Node* r) {
    if (!r) return r;
    if (r->data == value) {
        if (r->left == NULL && r->right == NULL) {
            delete r;
            return NULL;
        }
        else if (r->left != NULL && r->right == NULL) {
            Node *tmp = r->left;
            delete r;
            return tmp;
        }
        else if (r->left == NULL && r->right != NULL) {
            Node *tmp = r->right;
            delete r;
            return tmp;
        }
        else if (r->left && r->right) {
            Node* max = findMax(r->left);
            int maxValue = max->data;
            r->data = maxValue;
            r->left = deleteNode(maxValue, r->left);

        }
    }
    else if (value < r->data)
        r->left = deleteNode(value, r->left);
    else if (value > r->data)
        r->right = deleteNode(value, r->right);
    return r;
}
