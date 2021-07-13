#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vii vector<pii>
#define INF 1000000000
// <node, weight>
vector<pii> g[100001];
vector<int> dis(100001, INF);
void djk(int a){
    priority_queue< pii, vector <pii> , greater<pii> > pq;
    pq.push(make_pair(0, a));
    dis[a] = 0;
    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for (auto i: g[u]){
            int v = i.first, weight = i.second;
            if (dis[v] > dis[u] + weight){
                dis[v] = dis[u] + weight;
                pq.push(make_pair(dis[v], v));
            }
        }
    }
}
int32_t main()
{
    int tot_mID;
    cin >> tot_mID;
    for(int i=0, x; i<tot_mID; i++) cin >> x;
    int edges, a, b;
    cin >> edges;
    for(int i=0, x, y, cost; i<edges; i++)
        cin >> x >> y >> cost, g[x].push_back({y, cost});
    cin >> a >> b;
    // dijkstra find sp from a-b
    djk(a);
    cout << dis[b] << endl;
}
