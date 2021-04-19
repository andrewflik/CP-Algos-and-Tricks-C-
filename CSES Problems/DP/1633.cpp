#include<bits/stdc++.h>
const int mod = 1e9+7;
using namespace std;
int dp[1000005];
void s(int n){
    dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 4;
    dp[4] = 8, dp[5] = 16, dp[6] = 32;
    for(int i=7; i<n+1; i++)
        dp[i] = (dp[i-1]%mod + dp[i-2]%mod + dp[i-3]%mod + dp[i-4]%mod + dp[i-5]%mod + dp[i-6]%mod)%mod;
    cout << dp[n];
}
int main(){
    fill(dp, dp+1000005, 0);
    int n;
    cin >> n;
    s(n);
}