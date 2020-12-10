/*
    Author - Devesh
    Problem - Roads and Libraries (HackerRank)
    Topic - DSU & Connected Components
*/
#include<bits/stdc++.h>
using namespace std;
void dfs(int curr, vector<int> &v, vector<int> g[]){
    if(v[curr]) return;
    v[curr] = 1;
    for(auto i : g[curr])
        dfs(i, v, g);
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        long cl, cr;   // cl -> cost of lib and cr -> cost of road
        cin >> n >> m >> cl >> cr;
        vector<int> g[n+1], v(n+1, 0);
        for(int i=0, x, y; i<m; i++){
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        if(cr >= cl){
            cout << n * cl << endl;
        }else{
            int connectedComp = 0;
            for(int i=1; i<=n; i++){
                if(!v[i])
                    dfs(i, v, g), connectedComp++;
            }
            cout << (connectedComp * cl) + (n-connectedComp) * cr << endl;
        }
    }
}