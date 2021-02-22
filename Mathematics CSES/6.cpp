#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll mod = 1e9+7;
ll gs(ll n){
    return (((n%mod)*((n+1)%mod)%mod)*(mod+1)/2)%mod;
}
int main(){
    ll n, ans = 0;
    cin >> n;
    for(ll l=1, r; l<=n; l=r+1){
        r = n/(n/l);
        ans += ((n/l)%mod * ((gs(r)%mod - gs(l-1)%mod) + mod)%mod)%mod;
    }
    cout << ans%mod;
}