/*
    Problem - Building Roads
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
vector<int> g[maxn+5], v(maxn+5), r;
void dfs(int s){
    if(v[s]) return;
    v[s] = 1;
    for(auto i : g[s])
        dfs(i);
}
int main(){
    int n, m, k=0;
    cin >> n >> m;
    for(int i=0, x,y; i<m; i++)
        cin >> x >> y, g[x].push_back(y), g[y].push_back(x);
    for(int i=1; i<=n; i++)
        if(!v[i]) k++, dfs(i), r.push_back(i);
    cout << r.size()-1 << "\n";
    for(int i=1; i<r.size(); i++)
        cout << r[i-1] << " " << r[i] << endl;
}