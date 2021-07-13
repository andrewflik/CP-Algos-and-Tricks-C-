// Q3 - Mid point ll
#include <bits/stdc++.h>
using namespace std;
vector<int> g[1005];
int32_t main(){
    int n, m, c, t;
    cin >> n >> m >> t >> c;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    if(n == 2){
        cout << t << endl;
        return 0;
    }
    // Graph Input
    for(int i=0, u, v; i<m; i++) cin >> u >> v, g[u].push_back(v), g[v].push_back(u); 
    // BFS -> Find shorted path and use that
    queue<int> q; // {node, min_len}
    vector<bool> v(n+1, false);
    vector<int> dist(n+1, INT_MAX);
    int path = 0;
    q.push(1), v[1] = true, dist[1] = 0;
    while(!q.empty()){
        int curr = q.front(); q.pop();
        if(curr == n){
            break;
        }
        for(auto i : g[curr]){
            if(!v[i])
                q.push(i), v[i] = true, dist[i] = dist[curr] + 1;
        }
    }
    // cout << dist[n] << endl;
    // dist[n] stores the shortest path to 'n'
    int te = 0, nt = 0;
    for(int i=0; i < dist[n]; i++){
        int area = ceil(floor(te/t));
        if(area%2==0)
            te += c;
        else 
            te += c + (nt-te);
        while(nt <= te)
            nt += t;
        //cout << te << " " << nt << endl;
    }
    cout << te << endl;
}