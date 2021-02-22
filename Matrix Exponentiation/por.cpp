/*
    Author - Taha
    Problem - SEQ
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1LL*1e9+7;
ll ar[4][4], r[4][4], t[4][4], w[6][6], r1[4][4], t1[4][4];
void exp(ll p){
    while(p){
        if(p&1){
            // r * ar
            for(int i=1; i<=3; i++)
                for(int j=1; j<=3; j++){
                    t[i][j] = 0;
                    for(int l=1; l<=3; l++)
                        t[i][j] += (r[i][l] * ar[l][j])%mod;
            }
            for(int i=1; i<=3; i++)
                for(int j=1; j<=3; j++)
                    r[i][j] = t[i][j];
        }
                    // r * ar
        for(int i=1; i<=3; i++)
            for(int j=1; j<=3; j++){
                t[i][j] = 0;
                for(int l=1; l<=3; l++)
                    t[i][j] += (ar[i][l] * ar[l][j])%mod;
        }
        for(int i=1; i<=3; i++)
            for(int j=1; j<=3; j++)
                ar[i][j] = t[i][j];
        p >>= 1;
    }
}
void exp1(ll p){
    while(p){
        if(p&1){
            // r * ar
            for(int i=1; i<=3; i++)
                for(int j=1; j<=3; j++){
                    t[i][j] = 0;
                    for(int l=1; l<=3; l++)
                        t1[i][j] += (r1[i][l] * w[l][j])%mod;
            }
            for(int i=1; i<=3; i++)
                for(int j=1; j<=3; j++)
                    r1[i][j] = t1[i][j];
        }
                    // r * ar
        for(int i=1; i<=3; i++)
            for(int j=1; j<=3; j++){
                t1[i][j] = 0;
                for(int l=1; l<=3; l++)
                    t1[i][j] += (w[i][l] * w[l][j])%mod;
        }
        for(int i=1; i<=3; i++)
            for(int j=1; j<=3; j++)
                w[i][j] = t1[i][j];
        p >>= 1;
    }
}
ll exp2_(ll n, ll p){
    if(p == 1)
        return n%mod;
    ll res = 1LL;
    while(p){
        if(p&1)
            res = res*n%mod;
        p >>= 1, n = n*n%mod;
    }
    return res;
}
int main(){
    ll n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    n %= mod, f1 %= mod, f2 %= mod, f3 %= mod, c %= mod;
    ar[2][1] = ar[3][2] = ar[1][1] = ar[1][2] = ar[1][3] = 1LL;
    r[1][1] = r[2][2] = r[3][3] = 1LL;
    r1[1][1] = r1[2][2] = r1[3][3] = 1LL;
    w[1][1] = w[1][2] = w[1][3] = w[1][4] = w[1][5] = 1;
    w[2][1] = w[3][2] = w[4][4] = w[4][5] = w[5][5] = 1;
    exp(n-3);
    exp1(n-3);
    ll k = r1[1][5] * 2;
    cout << k << endl;
    ll ans = (exp2_(c, k) * exp2_(f3, r[1][1])%mod * exp2_(f2, r[1][2])%mod * exp2_(f1, r[1][3])%mod)%mod; 
    cout << ans;
    for(int i=1 ;i<=3; i++){
        cout << endl;
        for(int j=1; j<=3; j++)
            cout << r[i][j] << " ";
    }
}