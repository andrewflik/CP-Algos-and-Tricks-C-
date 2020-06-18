/*
	Author - Devesh
	Topic - Graph using Adjacency List
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 20;
int n, m;	// Total Nodes, Vertices
vector<int> G[maxn], visited(maxn, false);

void dfs(int n){
	if(visited[n])	return;
	cout << n << " ";
	visited[n] = true;
	for(auto x: G[n])	
		dfs(x);
}
void dfs2(int n){
	stack<int> s;
	s.push(n), visited[n] = true;
	while(!s.empty()){
		int e = s.top(); s.pop();
		cout << e << " ";
		for(auto i: G[e])
			if(!visited[i])
				s.push(i), visited[i] = true;
	}
}
void bfs(int n){
	queue<int> q;
	q.push(n), visited[n] = true;
	while(!q.empty()){
		int e = q.front(); q.pop();
		cout << e << " ";
		for(auto i: G[e])
			if(!visited[i])
				q.push(i), visited[i] = true;
	}
}
int main(){
	cin >> n >> m;
	for(int i=0, a, b; i<m; i++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	//dfs(1);
	//dfs2(1);
	bfs2(1);
}
