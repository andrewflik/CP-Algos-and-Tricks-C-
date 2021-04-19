/*
    Problem - Building Teams
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1e5;
vector<int> g[maxn+5], v(maxn+5, -1), used(maxn+5);
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i=0, x,y; i<m; i++)
        cin >> x >> y, g[x].push_back(y), g[y].push_back(x);
    for(int i=1; i<=n; i++)
        if(v[i] == -1){
        queue<int> q;
        q.push(i);
        used[i] = v[i] = 1;
        while(!q.empty()){
            int curr = q.front(); q.pop(); 
            for(auto c : g[curr]){
                if(!used[c]){
                    used[c] = 1;
                    if(v[c] == -1){
                        v[c] = (v[curr] == 1 ? 2 : 1);
                    }
                    q.push(c);
                }else{
                    if(v[curr] == v[c]){
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
        cout << v[i] << " ";
}