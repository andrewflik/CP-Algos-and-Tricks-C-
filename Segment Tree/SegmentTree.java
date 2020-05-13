class SegmentTree{
    int tree[], s; // Segment Tree
    SegmentTree(int n){
        int p, size;
        p = (int) Math.ceil((Math.log(n)/Math.log(2)));
        size = (int) Math.pow(2, p);
        size *= 2;
        s = size;
        tree = new int[size];
    }
    public void build(int cn, int ar[], int l, int r){
        if(l == r) {
            tree[cn] = ar[l];
            return;
        }
        int mid = (l+r)/2;
        build(cn*2, ar, l, mid);
        build(cn*2+1, ar, mid+1, r);
        tree[cn] = tree[cn*2] + tree[cn*2+1];
    }
    void print(){
        for(int i=1; i<s; i++)
            System.out.print(tree[i] + " ");
    }
    void update(int cn, int ar[], int l, int r, int p, int n){
        if(l == r){
            tree[cn] = ar[p] = n;
            return;
        }
        int mid = (l+r)/2;
        if(p > mid)
            update(cn*2+1, ar, mid+1, r, p, n);
        else
            update(cn*2, ar, l, mid, p, n);
        tree[cn] = tree[cn*2] + tree[cn*2+1]; 
    }
    int query(int cn, int l, int r, int ql, int qr){
        // Out of Bound
        if(ql > r || qr < l)
            return 0;
        // Completely Inside
        if(ql <= l && qr >= r)
            return tree[cn];
        int mid = (l+r)/2;
        return query(cn*2, l, mid, ql, qr) + query(cn*2+1, mid+1, r, ql, qr);
    }
}
