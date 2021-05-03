#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int ar[100005];
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=0; i<n; i++) cin >> ar[i];
        long long tot = 0, k = 1;
        for(int i=1; i<n; i++){
            if(ar[i] >= ar[i-1]) k++;
            else tot +=(k*(k+1)/2), k=1;
        }
        tot+=(1ll*k*(k+1)/2);
        cout << tot << endl;
    }
}