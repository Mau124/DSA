#include<bits/stdc++.h>
using namespace std;

// Program that shows how to implement a basic heap
#define MAX 100

int heap[MAX] = {0};
int n = 0;

void insert(int heap[], int value) {
    int i, k;
    i = n++;
    heap[i] = value;
    while(i > 0 && heap[(i-1)/2] < heap[i]) {
        k = heap[(i-1)/2];
        heap[(i-1)/2] = heap[i];
        heap[i] = k;
        i = (i-1)/2;
    }
}

int del(int heap[]) {
    int i, k, r;
    r = heap[0];
    n--;
    heap[0] = heap[n];
    i = 0;
    while(2*i+1 < n) {
        if(2*i+2 < n && heap[2*i+2] > heap[2*i+1]) {
            k=2*i+2;
        } else {
            k=2*i+1; 
        }
        if(heap[k] > heap[i]) {
            i = k;
            k = heap[(i-1)/2];
            heap[(i-1)/2] = heap[i];
            heap[i] = k;
        } else {
            break;
        }
    }
    return r;
}

void print(int heap[]) {
    for(int i=0; i<n; ++i) {
        cout << heap[i] << " ";
    }
    cout << "\n";
}

int main() {
    // Inserting to the heap
    insert(heap, 8);
    insert(heap, 5);
    insert(heap, 1);
    insert(heap, 3);
    insert(heap, 2);

    // Printing heap
    print(heap);

    // deleting some elements and showing the result
    cout << "Deleting " << del(heap) << " element " << endl;
    print(heap);

    cout << "Deleting " << del(heap) << " element " << endl;
    print(heap);

    return 0;
}
