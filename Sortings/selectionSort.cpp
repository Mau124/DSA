#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b) {
    int aux = a;
    a = b;
    b = aux;
}

void selectionSort(int arr[], int size) {
    for(int i=0; i<size-1; ++i) {
        int min = i;
        for(int j=i+1; j<size; ++j) {
            if(arr[j] < arr[min]) 
                min = j;
        }
        if(i != min) 
            swap(arr[i], arr[min]);
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
    selectionSort(arr, size);
    printArr(arr, size);

    return 0;
}
