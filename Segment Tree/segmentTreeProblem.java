/* Written by - lonecoder978 */
/* CodeForces 339-D */

import java.lang.Math;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class main{
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int n, m, p, b, tot;
        n = sc.nextInt();
        m = sc.nextInt();
        tot = (int)Math.pow(2, n);
        int ar[] = new int[tot];
        for(int i=0; i<tot; i++)
            ar[i] = sc.nextInt();
        SegmentTree t = new SegmentTree(tot);
        int k[] = new int[1];
        k[0] = -1;
        t.build(1, ar, 0, tot-1, k);
        //System.out.println(t.query());
        while(m-- > 0){
            p = sc.nextInt();
            b = sc.nextInt();
            t.update(1, ar, 0, tot-1, p-1, b, k);
            int ans = t.query();
            System.out.println(ans);
        }
    }


    /*************************************************************/
    public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }
}
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
    public void build(int cn, int ar[], int l, int r, int k[]){
        if(l == r) {
            tree[cn] = ar[l];
            k[0] = 0;
            return;
        }
        int mid = (l+r)/2;
        build(cn*2, ar, l, mid, k);
        build(cn*2+1, ar, mid+1, r, k);
        if(k[0] == 0) {
            tree[cn] = tree[cn * 2] | tree[cn * 2 + 1];
         //   System.out.println(tree[cn] + " | " + tree[cn*2] + " " + tree[cn*2+1]);
            k[0] = 1;
        }
        else {
            tree[cn] = tree[cn * 2] ^ tree[cn * 2 + 1];
         //   System.out.println(tree[cn] + " ^ " + tree[cn*2] + " " + tree[cn*2+1]);
            k[0] = 0;
        }
    }
    void print(){
        for(int i=1; i<s; i++)
            System.out.print(tree[i] + " ");
    }
    void update(int cn, int ar[], int l, int r, int p, int n, int k[]){
        if(l == r){
            tree[cn] = ar[p] = n;
            k[0] = 0;
            return;
        }
        int mid = (l+r)/2;
        if(p > mid)
            update(cn*2+1, ar, mid+1, r, p, n, k);
        else
            update(cn*2, ar, l, mid, p, n, k);

        if(k[0] == 0) {
            tree[cn] = tree[cn * 2] | tree[cn * 2 + 1];
            k[0] = 1;
        }
        else {
            tree[cn] = tree[cn * 2] ^ tree[cn * 2 + 1];
            k[0] = 0;
        }
    }
    int query(/*int cn, int l, int r, int ql, int qr*/){
        // Out of Bound
        /*if(ql > r || qr < l)
            return 0;
        // Completely Inside
        if(ql <= l && qr >= r)
            return tree[cn];
        int mid = (l+r)/2;
        return query(cn*2, l, mid, ql, qr) + query(cn*2+1, mid+1, r, ql, qr);*/
        return tree[1];
    }
}
