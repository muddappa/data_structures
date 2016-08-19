#include <BinaryTree.hh>
#include <BinarySearchTree.hh>

/*
           6
         /  \
        4    8
      /    /  \
     2    7    9
      \
       3

     Inorder: 2 3 4 6 7 8 9
     Preorder: 6 4 2 3 8 7 9
     PostOrder: 3 2 4 7 9 8 6
*/
int main()
{
    Node *l1 =  new Node(4, new Node(2, NULL, new Node(3, NULL, NULL)), NULL);
    Node *r1 = new Node(8, new Node(7, NULL, NULL), new Node(9, NULL, NULL));
    Node *root = new Node(6, l1, r1);
    
    BinaryTree *binaryTree = new BinaryTree(root);
    cout << "#######INORDER#######" << endl;
    binaryTree->inOrder();
    cout << "\n#######PREORDER######" << endl;
    binaryTree->preOrder();
    cout << "\n#######POSTORDER#####" << endl;
    binaryTree->postOrder();
    cout << endl;

    BinarySearchTree *bst = new BinarySearchTree();
    bst->insert(6);
    bst->insert(4);
    bst->insert(2);
    bst->insert(3);
    bst->insert(8);
    bst->insert(7);
    bst->insert(9);
    cout << "#######INORDER#######" << endl;
    bst->inOrder();
    cout << endl;

    cout << "#######SEARCH#######" << endl;
    Node* n = bst->search(8);
    cout << n->data << endl;
    bst->deleteNode(4);
    cout << "#######INORDER#######" << endl;
    bst->inOrder();
    cout << endl;
    bst->insertOnCondition(1, 1);
    cout << "#######INORDER#######" << endl;
    bst->inOrder();
    cout << endl;

    bst->insertOnCondition(18, 3);
    cout << "#######INORDER#######" << endl;
    bst->inOrder();
    cout << endl;
    Node* near = bst->findNearest(20);
    cout << "Nearest Node for value " << 20 << " is " << near->data << endl;

    cout << "Finding two nodes whoes sum becomes 13" << endl;
    Node *node1 = NULL, *node2 = NULL;
    bst->findNodes(13, node1, node2);
    cout << node1->data << "\t" << node2->data << endl;
}
