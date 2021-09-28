#include<bits/stdc++.h>
using namespace std;

#define MAX_NODES 9

int value[MAX_NODES] = {2, 7, 2, 6, 5, 11, 5, 9, 4};
int l[MAX_NODES] = {1, 2, -1, 6, -1, -1, -1, 8, -1};
int r[MAX_NODES] = {4, 3, -1, 5, 7, -1, -1, -1, -1};

int nodos = 0;

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

int main() {

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

    return 0;
}
