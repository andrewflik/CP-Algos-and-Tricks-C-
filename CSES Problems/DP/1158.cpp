#include<bits/stdc++.h>
using namespace std;
/*  Recurence realtion

    int ans = INT_MIN;
    void solve(int cost[], int pages[], int n, int maxPrice, int totPages){
        if(maxPrice >= 0)
            ans = max(totPages, ans);
        if(maxPrice < 0 or n < 0) return;    
        solve(cost, pages, n-1, maxPrice-cost[n], totPages+pages[n]);
        solve(cost, pages, n-1, maxPrice, totPages); 
    }
*/
int dp[2][100005];
void sw(){
    for(int i=0; i<100005; i++)
        dp[0][i] = dp[1][i], dp[1][i] = 0;   
}
int main(){
    int n, maxPrice;
    cin >> n >> maxPrice;
    int cost[n], pages[n];
    for(auto &i : cost) cin >> i;
    for(auto &i : pages) cin >> i;
    for(int i=0; i<n; i++){
        for(int j=0; j<=maxPrice; j++){
            if(j >= cost[i]) dp[1][j] = max(dp[0][j], pages[i]+dp[0][j-cost[i]]);
            else dp[1][j] = dp[0][j];
        }
        // swap work
        sw();
    }
    cout << dp[0][maxPrice];
}