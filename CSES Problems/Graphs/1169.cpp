#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int cs, ce, found = 0;
vector<int> g[maxn], used(maxn, 0), path(maxn, -1), lol;
void dfs(int node, int parent){
    used[node] = 1;
    for(auto i : g[node]){
        if(found) return;
        if(i == parent) continue;
        if(used[i] and found == 0){
            ce = node, cs = i, found = 1;
            return;
        }
        path[i] = node;
        dfs(i, node);
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i=1, x, y; i<=m; i++)
        cin >> x >> y, g[y].push_back(x), g[x].push_back(y);
    for(int i=1; i<=n; i++){
        if(!used[i]){
            dfs(i, path[i]);
            if(found){
                for(auto i=ce; i!=cs; i=path[i])
                    lol.push_back(i);
                lol.push_back(cs);
                reverse(lol.begin(), lol.end());
                lol.push_back(cs);
                cout << lol.size() << "\n";
                for(auto i : lol) cout << i << " ";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}