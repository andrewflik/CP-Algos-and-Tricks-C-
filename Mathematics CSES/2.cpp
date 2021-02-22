#include<bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;
long long exp2(int n, int p, long long m){
    long long r = 1;
    while(p){
        if(p&1)
            r=(1ll*r%m*n%m)%m;
        p>>=1, n=(1ll*n%m*n%m)%m;
    }
    return r;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << exp2(a, b, mod) << endl;
    }
}