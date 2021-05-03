// Count Sorted Vowel Strings
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int dp[5][n];
    for(int i=0; i<5; i++)
        for(int j=0; j<n; j++) dp[i][j] = 0;
    for(int i=0; i<n; i++) dp[0][i] = 1;
    for(int j=1; j<5; j++) dp[j][0] += dp[j-1][0] + 1;
    for(int i=1; i<5; i++){
        for(int j=1; j<n; j++) 
            dp[i][j] += dp[i][j-1] + dp[i-1][j];
    }
    cout << dp[4][n-1] << endl;
}