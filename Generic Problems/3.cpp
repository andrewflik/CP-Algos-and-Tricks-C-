#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        int mask = 1, last, totalSetbits = __builtin_popcount(n), d = log2(n);
        int a = 0, b = 0;
        for(int i=d, count = 1; i>=0; i--){
            if((mask<<i)&n and count == 1){
                a += mask<<i;
                count++;
            }else if((mask<<i)&n){
                // 1 bit
                b += mask<<i;
            }else{
                // 0 bit
                a += mask<<i;
                b += mask<<i;
            }
        }
        cout << a * b << endl;
    }
}