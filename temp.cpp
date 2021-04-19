#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int mat[7][7], tot = 0;
void dfs(int i, int j, int n){
    if((i>=0&&j>=0)&&(i<n&&j<n)){
        if(mat[i][j]) return;
        mat[i][j] = 1;
        if(i==6&&j==0){ // last cell
            tot++;
            return;
        }
        dfs(i+1, j, n);
        dfs(i, j+1, n);
        dfs(i-1, j, n);
        dfs(i, j-1, n);
        mat[i][j] = 0;
    }
}
int32_t main(){
    dfs(0, 0, 7);
    cout << tot;
}