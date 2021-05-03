#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void dfs(vector<vector<char>> &v, int n, int i, int j){
    int dx[] = {-1, 0, 1, 0, -1, 1, -1, 1};
    int dy[] = {0, -1, 0, 1, -1, 1, 1, -1};
    if((i>=0&&j>=0)&&(i<n&&j<n)&&(v[i][j]=='S')){
        v[i][j] = '.';
        for(int ii=0; ii<8; ii++) 
            dfs(v, n, i+dx[ii], j+dy[ii]);
    }
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, c=0;
        cin >> n;
        vector<vector<char>> v(n, vector<char>(n));
        for(auto &i : v)
            for(auto &j : i) cin >> j;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                if(v[i][j] == 'S') c++, dfs(v, n, i, j);
        }
        if(c&1) cout << "Alice\n";
        else cout << "Bob\n";
    }
}