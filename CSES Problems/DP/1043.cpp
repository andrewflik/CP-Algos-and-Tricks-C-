#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int32_t main(){
    int n, k;
    cin >> n;
    int ar[n], dp[n];
    dp[0] = ar[0];
    for(int i=0; i<n; i++) cin >> ar[i];
    for(int i=1; i<n; i++){
        // go back 'k' steps
        for(int j=i; j>=i-k&&j>=0; j--)
            dp[i] = max(dp[j-1]+ar[j]*(i-j+1), dp[i]);
    }
    cout << dp[i];
}

/*
7
1 15 7 9 2 5 10
3
*/