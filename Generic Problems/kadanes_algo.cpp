/*
    Author - Devesh
    Implementation for Kadane's Algorithm
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ar[n];
    for(int i=0; i<n; i++)
        cin >> ar[i];
    // Kadanes Algorithm - O(n)
    // S.C - O(n)
    int dp[n], maxn = ar[0];
    dp[0] = ar[0];
    for(int i=1; i<n; i++){
        dp[i] = max(dp[i-1] + ar[i], ar[i]);
        maxn = max(dp[i], maxn);
    }
    cout << maxn;
}