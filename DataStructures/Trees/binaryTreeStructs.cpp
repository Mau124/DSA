/*
 *   Simple implementation of a binary tree with simple operations
 *
 *   Part of the code was got from:
 *   https://www.geeksforgeeks.org/binary-tree-set-1-introduction/
 *  
 * */

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    struct Node* left;
    struct Node* right;

    Node(int value) {
        this->value = value;

        left = NULL;
        right = NULL;
    }
};

void preOrder(Node* next) {
    if(next == NULL)
        return;
    cout << next->value << " ";
    preOrder(next->left);
    preOrder(next->right);
}

void inOrder(Node* next) {
    if(next == NULL)
        return;

    inOrder(next->left);
    cout << next->value << " ";
    inOrder(next->right);
}

void postOrder(Node* next) {
    if(next == NULL)
        return;

    postOrder(next->left);
    postOrder(next->right);
    cout << next->value << " ";
}

int main() {
    // We create a root node
    struct Node* root = new Node(1);

    /*
     * Graphical structure of the tree
     *
     *          1
     *        /   \
     *      NULL NULL
     * */

    root->left = new Node(2);
    root->right = new Node(3);

    /*
     * Graphical structure of the tree
     *
     *          1
     *        /   \
     *       2     3
     *      / \   / \
     *     N  N  N  N
     * */

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    /*
     * Graphical structure of the tree
     *
     *          1
     *        /   \
     *       2     3
     *      / \   / \
     *     4   5  N  N
     *    / \ / \
     *   N  N N N
     * */

    // Tree traversal
    // Pre-order
    cout << "Tree traversal in Pre-order" << endl;
    preOrder(root);
    cout << "\n";

    // In-order
    cout << "Tree traversal in In-order" << endl;
    inOrder(root);
    cout << "\n";

    // Post-order
    cout << "Tree traversal in Post-order" << endl;
    postOrder(root);
    cout << "\n";
    
    return 0;
}
