// Recurrence rel - f(s-a[i]) + f(s)    - 0 or 1
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
    for(int i=0; i<n; i++){
        for(int j=1; j<=s; j++){
            if(j-ar[i]>=0)
                dp[j] = (dp[j] + dp[j-ar[i]])%mod;
        }
    }
    cout << dp[s];
}