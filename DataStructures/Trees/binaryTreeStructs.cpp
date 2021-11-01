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

// Insert as a binary search tree
void insert(Node* node, int val) {
    if(val > node->value) {
        if(node->right == NULL) {
            node->right = new Node(val);
        } else {
            insert(node->right, val);
        }
    } else {
        if(node->left == NULL) {
            node->left = new Node(val);
        } else {
            insert(node->left, val);
        }
    } 
}

// Check if a value exist in a binary search tree
bool search(Node* node, int val) {
    if(node == NULL)
        return false;

    if(node->value == val) {
        return true;
    } else if(node->value > val) {
        return search(node->left, val);
    } else {
        return search(node->right, val);
    }
}

int main() {
    // We create a root node
    struct Node* root = new Node(8);

    insert(root, 4); 
    insert(root, 5);
    insert(root, 9);
    insert(root, 10);
    insert(root, 3);

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

    // Check if 5 is 10 is inside the binary search tree
    cout << "5 is inside: " << search(root, 5) << endl;
    // Check if 87 is inside the binary search tree
    cout << "87 is inside: " << search(root, 87) << endl;
    
    return 0;
}
