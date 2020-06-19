/*
    Author - Devesh
	Graph Problem - So NP(HackerEarth)
*/
#include<iostream>
#include<vector>
using namespace std;
const int maxn = 100001;
int n, m, k, visited[maxn];
vector<int> G[maxn];
void dfs(int n){
	if(visited[n]) return;
	visited[n] = true;
	for(auto i: G[n])
		dfs(i);
}
int totalConnectedComp(int n){
	int c = 0;
	for(int i=1; i<=n; i++){
		if(!visited[i])
			dfs(i), c++;
	}
	return c;
}
int main(){
	cin >> n >> m >> k;
	for(int i=1, a, b; i<=m; i++){
		cin >> a >> b;
		G[a].push_back(b), G[b].push_back(a);
	}
	if(totalConnectedComp > k)
		cout << -1 << endl;
	else
		cout << m-n+k << endl;
}
