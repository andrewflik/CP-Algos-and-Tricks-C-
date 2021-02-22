#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
int c[maxn];
int main(){
    for(int i=2; i<maxn; i++){
        for(int j=i; j<maxn; j+=i){
            c[j]++;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // int ans = 0;
        // for(int i=1; i*i<=n; i++){
        //     if(n%i==0){
        //         ans++;
        //         if(n/i!=i) ans++;
        //     }
        // }
        // cout << ans << endl;
        cout << c[n]+1 << endl;
    }
}