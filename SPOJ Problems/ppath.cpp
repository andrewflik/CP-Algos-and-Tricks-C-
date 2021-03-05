/*
    Author - Devesh
    Problem - PPATH
    Hint - Sieve + BFS
    A very beautiful problem
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+1;
bool p[maxn];
void sieve(){
    fill(p, p+maxn, true);
    p[0] = p[1] = false;
    for(int i=2; i*i<maxn; i++){
        if(p[i]){
            for(int j=i+i; j<maxn; j+=i)
                p[j] = false;
        }
    }
}
vector<int> g[maxn], v(maxn, false);
void solve(){
    for(int n=1001; n<=9999; n+=2){
        if(p[n]){
            for(int i=0; i<=3; i++){
                string t = to_string(n);
                for(int j=1; j<=9; j++){
                    t[i] = j+'0';
                    if(stoi(t)!=n and p[stoi(t)])
                        g[stoi(t)].push_back(n), g[n].push_back(stoi(t));
                }
            }
        }
    }
}
int bfs(int src, int dest){
    for(int i=1001; i<=9999; i+=2) v[i] = false;
    int ans = 0, cost = INT_MAX;
    queue<pair<int, int>> q;
    q.push({src, 0});
    while(!q.empty()){
        int curr = q.front().first, c = q.front().second;
        if(curr == dest) {cost = min(cost, c); break;}
        //cout << curr << endl;
        v[curr] = 1;
        q.pop();
        for(auto i : g[curr])
            if(!v[i])   q.push({i, c+1});
    }
    return cost;
}
int main(){
    sieve();
    solve();
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << bfs(a, b) << "\n";
    }
}