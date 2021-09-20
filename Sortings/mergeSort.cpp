#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int r) {
    int size = (r-l)+1, m = l+(r-l)/2;
    int ptr1 = l, ptr2 = m+1, i = 0, aux[size];

    while(ptr1 <= m || ptr2 <= r) {
        if(ptr1 <= m && ptr2 <= r) {
            if(arr[ptr1] >= arr[ptr2]) {
                aux[i++] = arr[ptr2++];
            } else {
                aux[i++] = arr[ptr1++];
            }
        } else if(ptr1 <= m) {
            aux[i++] = arr[ptr1++];
        } else {
            aux[i++] = arr[ptr2++];
        }
    }

    for(i = 0; i < size; ++i) 
        arr[l+i] = aux[i];
}

void mergeSort(int arr[], int  l, int r) {
    if(l >= r)
        return;

    int m = l + (r-l)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, r);
}

void printArr(int arr[], int size) {
    for(int i=0; i<size; ++i) 
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int size = 10;
    int arr[] = {9, 7, 5, 6, 2, 1, 4, 3, 0, 8};

    cout << "Unsorted array" << endl;
    printArr(arr, size);
    cout << "Sorted array" << endl;
    mergeSort(arr, 0, 9);
    printArr(arr, size);

    return 0;
}
