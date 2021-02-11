/*
    Author - Devesh
    Problem - SEQ
*/

#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const long long mod = 1000000000;
int ar[11][11], t[11][11], r[11][11];
void exp(int k, int n){
    while(n){
        if(n&1) {
            for(int i=1; i<=k; i++){
                for(int j=1; j<=k; j++){
                t[i][j] = 0;
                    for(int l=1; l<=k; l++)
                        t[i][j] += (r[i][l]%mod * ar[l][j]%mod)%mod;
                }
            }
            for(int i=1; i<=k; i++)
                for(int j=1; j<=k; j++)
                    r[i][j] = t[i][j];
        }
        for(int i=1; i<=k; i++){
            for(int j=1; j<=k; j++){
                t[i][j] = 0;
                for(int l=1; l<=k; l++)
                    t[i][j] += (ar[i][l]%mod * ar[l][j]%mod)%mod;
            }
        }
        for(int i=1; i<=k; i++)
            for(int j=1; j<=k; j++)
                ar[i][j] = t[i][j];
        n >>= 1;
    }
}

int32_t main(){
    int h;
    cin >> h;
    while(h--){
        int n, k;
        cin >> k;
        for(int i=0; i<=k; i++)
            for(int j=0; j<=k; j++)
                ar[i][j] = r[i][j] = t[i][j] = 0;

        vector<int> c(k+1, 0), b(k+1, 0);
        // Init R to Identity Matrix
        for(int i=1; i<=k; i++) r[i][i] = 1;

        for(int i=k; i>=1; i--) cin >> b[i];
        for(int i=1; i<=k; i++) cin >> c[i];
        cin >> n;
        if(n <= k){
            cout << b[n] << endl;
            continue;
        }
        for(int i=1; i<=k; i++)
            ar[1][i] = c[i];
        for(int i=2; i<=k; i++)
            ar[i][i-1] = 1;
        exp(k, n-k);
        int ans = 0;
        for(int i=1; i<=k; i++)
            ans += (r[1][i]%mod * b[i]%mod)%mod, ans %= mod;
        cout << ans%mod << endl;
        // for(auto i : r){
        //     cout << endl;
        //     for(auto j : i) cout << j << " ";
        // }
    }
}