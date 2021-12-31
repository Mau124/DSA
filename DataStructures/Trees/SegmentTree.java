import java.util.Random;

public class SegmentTree {
    public static void main(String[] args) {
        Random random = new Random(5);
        int T = 100;
        for(int tt=0; tt<T; ++tt) {

            // make random array
            int n = 1 + random.nextInt(10);
            int[] a = new int[n];
            for(int i=0; i<n; ++i) 
                a[i] = random.nextInt(10);

            SegTree st = new SegTree(0, n-1, a);

            // Answer queries
            int nQueries = 100;
            for(int qq=0; qq<nQueries; ++qq) {
                if(random.nextBoolean()) {
                    // range sum query
                    int l = random.nextInt(n);
                    int r = random.nextInt(n);
                    int ans = 0;
                    for(int i=l; i<=r; ++i) 
                        ans += a[i];

                    int stAns = st.rangeSum(l, r);

                    if(stAns != ans) throw null;
                }   else {
                    // point update query
                    int index = random.nextInt(n);
                    int newVal = random.nextInt(n);
                    a[index] = newVal;

                    st.pointUpdate(index, newVal);
                }
            }
        }

        System.out.println("All test passed");
    }

    static class SegTree {
        int sum;
        int leftmost, rightmost;
        SegTree lChild, rChild;

        public SegTree(int lefmost, int rightmost, int[] a) {
            this.leftmost = lefmost;
            this.rightmost = rightmost;

            if(leftmost == rightmost) {
                // leaf
                sum = a[leftmost];
            } else {
                // have two children
                int mid = leftmost + (rightmost-leftmost)/2;
                // [l, mid], [mid+1, r]
                lChild = new SegTree(leftmost, mid, a);
                rChild = new SegTree(mid+1, rightmost, a);
                recalc();
            }
        }

        public void recalc() {
            if(leftmost == rightmost) return;
            sum = lChild.sum + rChild.sum;
        }

        public void pointUpdate(int index, int newVal) {
            if(leftmost==rightmost) {
                // leaft
                sum = newVal;
                return;
            }
            // two kids
            if(index <= lChild.rightmost) 
                lChild.pointUpdate(index, newVal);
            else
                rChild.pointUpdate(index, newVal);

            recalc();
        }

        public int rangeSum(int l, int r) {
            // Case 1: It does not enter to that range
            if(l > rightmost || r < leftmost) return 0;

            // Case 2: It covers all range
            if(l<=leftmost && r>=rightmost) return sum;

            // Case 3: We don't know
            return lChild.rangeSum(l, r) + rChild.rangeSum(l, r);
        }
    }
}