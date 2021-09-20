#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b) {
    int aux = a;
    a = b;
    b = aux;
}

void bubbleSort(int arr[], int size) {
    for(int i=0; i<size; ++i) {
        for(int j=0; j<size-1; ++j) {
            if(arr[j] > arr[j+1]) 
                swap(arr[j], arr[j+1]);
        }
    }
}

void printArr(int arr[], int size) {
    for(int i=0; i<size; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int size = 10;
    int arr[10] = {9, 7, 5, 6, 2, 1, 4, 3, 0, 8};

    cout << "Unsorted array" << endl;
    printArr(arr, size);
    cout << "Sorted array" << endl;
    bubbleSort(arr, size);
    printArr(arr, size);

    return 0;
}
