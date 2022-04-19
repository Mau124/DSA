#include<iostream>
using namespace std;

// Class for min Heap
class Heap {
public:
    int values[1000];
    int N = 0;

    Heap() {}

    void inOrder(int index = 1) {
        if(index > N) 
            return;

        inOrder(2*index);
        cout << values[index] << " -> ";
        inOrder(2*index+1);
    }

    void insert(int newVal) {
        N++;
        values[N] = newVal;
        int tmp = N;
        while(values[tmp] < values[tmp/2] && tmp/2 > 0) {
            swap(values[tmp], values[tmp/2]);
            tmp/=2;
        }
    }

    int peek() {
        return values[1];
    }

    int pop() {
        int index = 1;
        int tmp = values[1];
        values[1] = values[N--];

        while(2*index <= N) {
            int k;
            if(2*index+1 <= N && values[2*index+1] < values[2*index]) {
                k = 2*index+1;
            } else {
                k = 2*index;
            }

            if(values[index] > values[k]) {
                swap(values[index], values[k]);
            } else {
                break;
            }

            index = k;
        }

        return tmp;
    }

private:
    
    void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
};

int main() {
    Heap myHeap;
    myHeap.insert(5);
    myHeap.inOrder();
    cout << "\n";
    cout << myHeap.peek() << endl;
    myHeap.insert(8);
    myHeap.inOrder();
    cout << "\n";
    myHeap.insert(2);
    myHeap.inOrder();
    cout << "\n";
    cout << myHeap.peek() << endl;
    myHeap.insert(1);
    myHeap.inOrder();
    cout << "\n";
    myHeap.insert(3);
    myHeap.inOrder();
    cout << "\n";
    myHeap.pop();
    myHeap.inOrder();
    cout << "\n";
    cout << myHeap.peek() << endl;
    myHeap.pop();
    myHeap.inOrder();
    cout << "\n";
    cout << myHeap.peek() << endl;
    myHeap.pop();
    myHeap.pop();
    cout << myHeap.peek() << endl;

    return 0;
}