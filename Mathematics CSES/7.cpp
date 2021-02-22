#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 1e9+7;
ll exp(ll n, ll p){
    n %= mod, p = p%(mod);
    ll r = 1;
    while(p){
        if(p&1)
            r=(r%mod*n%mod)%mod;
        p >>=1, n=(n%mod*n%mod)%mod;
    }
    return r%mod;
}
ll modInv(ll n){
    return exp(n, mod-2)%mod;
}
int main(){
    ll n, x, k;
    cin >> n;
    ll nd = 1, sd = 1, md = 1, t = 1;
    while(n--){
        cin >> x >> k; 
        x %= mod, k %= mod;
        t = (t%mod*exp(x, k)%mod)%mod;
        nd = (nd%mod*(k+1)%mod)%mod;
        nd %= mod;
        sd = (sd%mod*(((exp(x, k+1)%mod - 1%mod) + mod)%mod * modInv(x-1)%mod + mod)%mod)%mod;
        sd %= mod;
    }
    ll cp = (((nd)%(mod-1) * (mod+1)/2)%(mod-1))%(mod-1);
    md = (md%mod * exp(t, cp)%mod)%mod;
    if(nd&1)
        md = (md%mod * (ll)sqrt(t)%mod)%mod;
    cout << nd%mod << " " << sd%mod << " " << md%mod << endl;
}