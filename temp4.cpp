#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        int ar[n+2], l[n+1], r[n+1];
        ar[0] = ar[n+1] = 0;
        for(int i=1; i<=n; i++) cin >> ar[i];
        l[0] = 0;
        for(int i=1; i<=n; i++) l[i] = __gcd(l[i-1], ar[i]); 
        r[n] = 0;
        for(int i=n-1; i>=0; i--) r[i] = __gcd(r[i+1], ar[i+1]);
        
        // for(int i=0; i<=n; i++) cout << l[i] << " ";
        // cout << endl;
        // for(int i=0; i<=n; i++) cout << r[i] << " ";
        // cout << endl;
        reverse(r, r+n+1);
        while(q--){
            int ql, qr;
            cin >> ql >> qr; ql--, qr;
            cout << __gcd(l[ql],r[n-qr]) << endl;
        }
    }
}