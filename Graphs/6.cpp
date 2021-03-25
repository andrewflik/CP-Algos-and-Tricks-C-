#include<bits/stdc++.h>
#define ppi pair<int, int>
using namespace std;
map<ppi, ppi> g;
unordered_map<int, bool> v;
int bfs(int s, int d){
    int dist = INT_MAX, tot = 0;
    queue<int> q;
    v[s] = 1;
    while(!q.empty()){
        int curr = q.front();
        v[curr] = 1;
        for(auto i : g){
            if(d >= i.first.first and d <= i.first.second)
                dist = min(dist, tot);
            if(s >= i.first.first and s <= i.first.second){  // inside range
                for(int j=i.first.second; j<=i.second.second; j++)
                    if(!v[j])
                        q.push(j), tot++;
            }
        }
    }
    return dist;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        while(m--){
            ppi l;
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            l = {a, b};
            // if it exists
            if(g.find(l) != g.end())
                g[l] = {make_pair(min(g[l].first, c), max(g[l].second, d))};
            else
                g[l] = {c, d};
        }
        // for(auto i : g)
        //     cout << i.first.first << " " << i.first.second << " - " 
        //     << i.second.first << " " << i.second.second << endl;
        cout << bfs(x, y) << endl;
    }
}