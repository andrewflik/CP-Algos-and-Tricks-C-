#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> v(1001, vector<char>(1001));
vector<vector<int>> dp(1001, vector<int>(1001, 0));
const long long mod = 1e9+7;
void dfs(int n){
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i][j]=='*'){
                dp[i][j]=0;
                continue;
            }
            else{
                if(i>0)
                    dp[i][j] = (dp[i][j]+dp[i-1][j])%mod;
                if(j>0)
                    dp[i][j] = (dp[i][j]+dp[i][j-1])%mod;
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    char x;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> v[i][j];
    dfs(n);
    cout << dp[n-1][n-1];
}