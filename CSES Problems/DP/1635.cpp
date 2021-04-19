// Recurrence rel - f(s-a[0]) + f(s-a[1]) + f(s-a[2]) ...
#include<bits/stdc++.h>
const long long mod = 1e9+7;
using namespace std;
int main(){
    int n, s;
    cin >> n >> s;
    int ar[n], dp[s+1];
    fill(dp, dp+s+1, 0);
    for(int i=0;i<n;i++)cin>>ar[i];
    dp[0]=1,dp[n]=0;
    for(int i=1; i<=s; i++){
        for(int j=0; j<n; j++)
            if(i-ar[j]>=0)
                dp[i] = (dp[i] + dp[i-ar[j]]) % mod;
    }
    cout << dp[s];
}