// Recurrence rel - f(n-d1) + f(n-d2)    - for very digit
#include<bits/stdc++.h>
using namespace std;
int dp[1000005];
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int curr = i, d, ans = INT_MAX;
        while(curr){
            d = curr%10;
            if(i-d>=0 && d!=0)
                ans = min(ans, dp[i-d] + 1);
            curr /= 10;
        }
        dp[i] += ans;
    }
    cout << dp[n];
}