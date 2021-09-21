#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> v, int value) {    
    int l = 0, r = v.size()-1;

    while(l <= r) {
        int m = l+(r-l)/2;

        if(v[m] == value) return m;
        if(v[m] > value) 
            r = m-1;
        else 
            l = m+1;
    }
    return -1;
}

int main() {
    // Vector must be sorted
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Test with a number that is in the vector" << endl;
    cout << binarySearch(v, 9) << "\n";

    cout << "Test with a number that is not in the vector" << endl;
    cout << binarySearch(v, 0) << "\n";

    return 0;
}
