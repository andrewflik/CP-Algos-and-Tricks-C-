#include<iostream>
using namespace std;
#define ll long long
ll fmul(ll n, ll f, ll c){
    ll p = 0, r = f;
    while(1){
        p += (n/r);
        if(r > n/f) break;
        r *= f;
    }
    return p/c;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, k, f, ans = 1LL<<62;
        cin >> n >> k;
        f = k;
        for(ll i=2, c=0; i*i<=f; i++){
            if(f%i == 0){
                c=0;
                while(f%i==0) f/=i, c++;
                ans = min(ans, fmul(n, i, c));
            }
        }
        if(f > 1)
            ans = min(ans, fmul(n, f, 1));
        cout << ans << "\n";
    }
}
