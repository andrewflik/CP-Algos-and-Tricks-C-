/*
    Problem - Message Route
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
vector<int> g[maxn+5], v(maxn+5), p;
void bfs(int d){
    queue<int> q;
    q.push(1);
    v[1] = 1;
    int path[d+1];
    while(!q.empty()){
        int curr = q.front(); q.pop();
        if(curr == d){
            for(int c=d; c!=1; c=path[c]) p.push_back(c);
            p.push_back(1);
            reverse(p.begin(), p.end());
            cout << p.size() << "\n";
            for(auto i : p) cout << i << " ";
            return;
        }
        for(auto i : g[curr])
            if(!v[i]) v[i] = 1, q.push(i), path[i] = curr;
    }
    cout << "IMPOSSIBLE\n";
}
int main(){
    int n, m, k=0;
    cin >> n >> m;
    for(int i=0, x,y; i<m; i++)
        cin >> x >> y, g[x].push_back(y), g[y].push_back(x);
    bfs(n);
}