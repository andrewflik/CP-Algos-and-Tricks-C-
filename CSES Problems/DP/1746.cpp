#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, mod = 1e9+7;
    cin >> n >> m;
    int ar[n], dp[n+1][m+1];
    memset(dp, 0, sizeof dp);
    for(int i=1; i<=m; i++) dp[1][i] = 1;
    for(int i=0; i<n; i++) cin >> ar[i];
    for(int i=1; i<=n-1; i++){
        if(ar[i-1] == 0){
            for(int j=1; j<=m; j++){
                // fill next layer completely
                if(j-1 >= 1) dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j]) % mod;
                if(j >= 1) dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
                if(j+1 >= 1) dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % mod;
            }
        }else{
            // fill next layer partially
            if(ar[i-1]-1 >= 1) dp[i+1][ar[i-1]-1] = (dp[i+1][ar[i-1]-1] + dp[i][ar[i-1]]) % mod;
            if(ar[i-1] >= 1) dp[i+1][ar[i-1]] = (dp[i+1][ar[i-1]] + dp[i][ar[i-1]]) % mod;
            if(ar[i-1]+1 >= 1) dp[i+1][ar[i-1]+1] = (dp[i+1][ar[i-1]+1] + dp[i][ar[i-1]]) % mod;
        }
    }
    // for(int i=1; i<=n; i++){
    //     cout << endl;
    //     for(int j=1; j<=m; j++)
    //         cout << dp[i][j] << " ";
    // }
    int ans = 0;
    // sum last layer
    if(ar[n-1] == 0)
        for(int i=1; i<=m; i++)
            ans = (ans + dp[n][i]) % mod;
    else
        ans = dp[n][ar[n-1]] % mod;
    cout << ans << endl;
}