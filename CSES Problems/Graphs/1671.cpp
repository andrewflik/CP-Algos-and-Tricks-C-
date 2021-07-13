#include<bits/stdc++.h>
#define int long long
const long long INF = LLONG_MAX;
using namespace std;
vector<pair<int, int>> g[100005];
vector<int> dist(100005, INF), seen(100005, false);
priority_queue<pair<int, int>> pq;
int32_t main()
{
    int n, m, a, b, c;
    cin >> n >> m;
    for(int i=0; i<m; i++)
        cin >> a >> b >> c, g[a].push_back({b, c});
    pq.push({dist[1]=0, 1});
    while(!pq.empty()){
        int curr = pq.top().second; pq.pop();
        if(seen[curr]) continue;
        seen[curr] = true;
        for(auto [v, w]: g[curr]){
            if(dist[v] > dist[curr] + w)
                dist[v] = dist[curr] + w, pq.push({-dist[v], v});
        }
    }
    for(int i=1; i<=n; i++) cout << dist[i] << " ";
}