/*
	Author - Devesh
	Topic - LCA
	Time Complexity - <O(n), O(n)>
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 17;
int n, m;
vector<int> T[maxn], visited(maxn, false), par(maxn), h(maxn);
void dfs(int n, int h, int p){
	if(visited[n]) return;
	visited[n] = true, ::h[n] = h, par[n] = p;
	for(auto x:T[n])
		dfs(x, h+1, n);
}
int LCA(int x, int y){
	if(par[x] == par[y])
		return par[x];
	if(h[x] < h[y])
		swap(x, y);
	return LCA(par[x], y);
}
int main(){
	cin >> n >> m;
	for(int i=1, x, y; i<=m; i++){
		cin >> x >> y;
		T[x].push_back(y), T[x].push_back(y);
	}
	dfs(1, 0, -1);
	cout << LCA(12, 7) << endl;
}

