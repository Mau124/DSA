#include<bits/stdc++.h>
using namespace std;

#define MAX_NODES 9

int value[MAX_NODES] = {0};
int l[MAX_NODES] = {0};
int r[MAX_NODES] = {0};

int nodes = 0;

/*
 * To create the next tree:
 *
 *                   2
 *                /     \
 *               7        5
 *             /   \     /  
 *            2    6    9
 *                / \  /
 *               5  11 4
 *
 * We need the next arrangement
 *
 * node   0  1  2  3  4  5  6  7  8 
 * value  2  7  2  6  5 11  5  9  4
 * left   1  2 -1  6 -1 -1 -1  8 -1
 * right  4  3 -1  5  7 -1 -1 -1 -1
 * */

/*
 * To insert data with this arrangement, it is necessary that the programmer
 * make the correct links
 **/

int createNodes(int data) {
    value[nodes] = data;   
    l[nodes] = -1;
    r[nodes] = -1;
    return nodes++;
}

void preOrder(int node) {
    if(node == -1)
        return;
    cout << value[node] << " ";       
    preOrder(l[node]);
    preOrder(r[node]);
}

void inOrder(int node) {
    if(node == -1)
        return;
    inOrder(l[node]);
    cout << value[node] << " ";
    inOrder(r[node]);
}

void postOrder(int node) {
    if(node == -1)
        return;
    postOrder(l[node]);
    postOrder(r[node]);
    cout << value[node] << " ";
}

// Insert as a binary search tree
void insert(int nodes, int val) {
    if(value[nodes] > val) {
        if(l[nodes] == -1) {
            l[nodes] = createNodes(val);
        } else {
            insert(l[nodes], val); 
        }
    } else {
        if(r[nodes] == -1) {
            r[nodes] = createNodes(val);
        } else {
            insert(r[nodes], val);
        }
    } 
}

// Search if an element exist in a binary search tree
bool search(int nodes, int val) {
    if(nodes == -1) 
        return false;

    if(value[nodes] == val) {
        return true;
    } else if(value[nodes] > val) {
        return search(l[nodes], val);
    } else {
        return search(r[nodes], val);
    }
}

int main() {

    // Insert into binart search tree
    int root = createNodes(8);
    insert(root, 4);
    insert(root, 5);
    insert(root, 9);
    insert(root, 10);
    insert(root, 3);

    // Tree traversal
    // Pre-order
    cout << "Tree traversal in Pre-Order" << endl;
    preOrder(0);
    cout << "\n";

    // In-order
    cout << "Tree traversal in In-order" << endl;
    inOrder(0);
    cout << "\n";

    // Post-order
    cout << "Tree traversal in Post-order" << endl;
    postOrder(0);
    cout << "\n";

    // Check if 5 is inside the tree
    cout << "5 is inside the tree: " << search(0, 5) << endl;
    // Check if 11 is inside the tree
    cout << "11 is inside the tree: " << search(0, 11) << endl;

    return 0;
}
