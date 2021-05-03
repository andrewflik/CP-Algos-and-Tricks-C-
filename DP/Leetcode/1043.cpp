#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int32_t main(){
    int n, k;
    cin >> n >> k;
    int ar[n], dp[n];
    for(int i=0; i<n; i++) cin >> ar[i], dp[i]=0;
    dp[0] = ar[0]; // base case
    for(int i=1; i<n; i++){
        int maxE = ar[i];
        // go back 'k' steps
        for(int j=0; j<k && i-j>=0; j++)
            maxE = max(maxE, ar[i-j]), dp[i] = max(dp[i], (i-j-1 >= 0 ? dp[i-j-1] : 0) + (j+1)*maxE);
    }
    for(int i=0; i<n; i++)
        cout << dp[i] << " ";
}

/*
7
1 15 7 9 2 5 10
3
*/
/*
11 4
1 4 1 5 7 3 6 1 9 9 3
*/