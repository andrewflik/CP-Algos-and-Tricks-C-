#include<bits/stdc++.h>
using namespace std;
void mbs(vector<vector<int>>& ar, int n, int m, int k) {
    vector<vector<int>> pre(n+2*k, vector<int>(m+2*k, 0)), ans(n, vector<int>(m, 0));
    pre[k][k] = ar[0][0];
    for(int i=k+1, j=1; i<m+2*k; i++, j++)
        pre[k][i] = pre[k][i-1] + (j < m ? ar[0][j] : 0);
    for(int i=k+1, j=1; i<n+2*k; i++, j++)
        pre[i][k] = pre[i-1][k] + (j < n ? ar[j][0] : 0);
    for(int i=k+1, ii = 1; i<n+2*k; i++, ii++)
        for(int j=k+1, jj = 1; j<m+2*k; j++, jj++)
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + (ii<n && jj<m ? ar[ii][jj] : 0);

    // for(int i=0; i<n+2*k; i++){
    //     cout << endl;
    //     for(int j=0; j<m+2*k; j++)
    //         cout << pre[i][j] << " ";
    // }
    for(int i=k; i<n+k; i++){
        int ans = 0;
        for(int j=k; j<m+k; j++){
            ans = pre[i+k][j+k]; 
            if(i-k>0)
                ans -= pre[i-k-1][j+k];
            if(j-k>0)
                ans -= pre[i+k][j-k-1];
            if(i-k>0 && j-k>0)
                ans += pre[i-k-1][j-k-1]; 
            cout << ans << " ";
        }
        cout << endl;
    }
    // for(int i=0; i<n; i++){
    //     cout << endl;
    //     for(int j=0; j<m; j++)
    //         cout << ans[i][j] << " ";
    // }
}
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> ar(n+k, vector<int>(m+k, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) 
            cin >> ar[i][j];
    mbs(ar, n, m, k);
}