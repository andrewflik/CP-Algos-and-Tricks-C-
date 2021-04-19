#include<bits/stdc++.h>
const int INF = 1e9;
using namespace std;
int dp[1000005], ar[1000005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s;
    cin >> n >> s;
    for(int i=0; i<n; i++) cin >> ar[i];
    for(int i=1; i<=s; i++){
        int ans = INF;
        for(int j=0; j<n; j++)
            if(i-ar[j]>=0)
                ans = min(ans, dp[i-ar[j]]+1);
        dp[i] = ans;
    }
    cout << (dp[s]==INF?-1:dp[s]);
}