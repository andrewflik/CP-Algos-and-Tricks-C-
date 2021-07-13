// Colorful Knapsack
#include<bits/stdc++.h>
using namespace std;
vector<int> sacks[1001]; // each sack will store a certain color of stones
int dp[100][10000];
int main(){
    int n, m, x;
    cin >> n >> m >> x;
    int ar[n];
    for(int i=0; i<n; i++)
        cin >> ar[i];
    for(int i=0, c; i<n; i++)
        cin >> c, sacks[c].push_back(ar[i]);
    // init DP
    for(int c=1; c<=m; c++){
        for(int i=1; i<=x; i++){        // i is x
            // iteratve over the given sack
            for(auto &j : sacks[c]){
                if(i-j >= 0)
                    dp[c][i] = max(dp[c][i-1], j+dp[c-1][i-j]); 
            }
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=x; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << x - dp[m][x] << endl;
}