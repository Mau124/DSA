#include<bits/stdc++.h>
using namespace std;

class SegTree {
public:
    int sum;
    int leftmost, rightmost;
    SegTree *lChild, *rChild;

    SegTree(int l, int r, int a[]) {
        leftmost = l;
        rightmost = r;

        if(leftmost == rightmost) {
            sum = a[leftmost];
        } else {
            int mid = leftmost + (rightmost - leftmost)/2;
            lChild = new SegTree(leftmost, mid, a);
            rChild = new SegTree(mid+1, rightmost, a);
            recalc();
        }
    }

    void recalc() {
        if(leftmost == rightmost)
            return;
        sum = lChild->sum + rChild->sum; 
    }
    
    void pointUpdate(int index, int newVal) {
        if(leftmost == rightmost) {
            sum = newVal;
            return;
        }
        
        if(index <= lChild->rightmost)
            lChild->pointUpdate(index, newVal);
        else
            rChild->pointUpdate(index, newVal);

        recalc();
    }

    int sumRange(int l, int r) {
        // Case 1: It does not cover that range
        if(l > rightmost || r < leftmost) return 0;

        // Case 2: It covers all the range
        if(l <= leftmost && r >= rightmost) return sum;

        // Case 3: It covers partially
        return lChild->sumRange(l, r) + rChild->sumRange(l, r);
    }
};

int main() {
    // Test segment Tree class
    int T = 100;
    for(int tt=0; tt<T; ++tt) {
        int n = rand() % 10 + 1; 
        int arr[n];

        for(int i=0; i<n; ++i) {
            arr[i] = rand() % 10;
        }

        SegTree st = SegTree(0, n-1, arr);

        // Answer queries
        int nQueries = 100;
        for(int qq=0; qq<nQueries; ++qq) {
            if(rand() % 2) {
                // range sum query
                int l = rand() % n;
                int r = rand() % n;
                int ans = 0;
                for(int i=l; i<=r; ++i)
                    ans += arr[i];

                int stAns = st.sumRange(l, r);

                if(stAns != ans) throw nanl; 
            } else {
                // point update
                int index = rand() % n;
                int newVal = rand() % n;
                arr[index] = newVal;

                st.pointUpdate(index, newVal);
            }  
        }
    }

    cout << "All test passed " << endl;


    return 0;
}
