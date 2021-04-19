#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int cs, ce;
vector<int> g[maxn], used(maxn, 0), path(maxn, -1), lol;
bool dfs(int node, int parent){
    used[node] = 1;
    for(auto i : g[node]){
        if(i == parent) continue;
        if(used[i]){
            ce = node, cs = i;
            return true;
        }
        path[i] = node;
        return dfs(i, node);
    }
    cout << node << endl;
    return false;
}
/*5 5
1 2
1 3
1 4
3 4
2 7*/
int main(){
    int n, m;
    cin >> n >> m;
    for(int i=1, x, y; i<=m; i++)
        cin >> x >> y, g[y].push_back(x), g[x].push_back(y);
    for(int i=1,j; i<=n; i++){
        j=dfs(i, path[i]);
        cout << j << endl;
        if(!used[i] && j){
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
    cout << "IMPOSSIBLE\n";
}