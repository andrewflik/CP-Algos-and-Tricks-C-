/*
	Author - Devesh
	Problem - Check if the given graph is Bi-partite
	Link - https://www.geeksforgeeks.org/bipartite-graph/
*/
#include<bits/stdc++.h>
using namespace std;
int n, m, visited[200], color[200], f=0;
vector<int> G[200];
// 1 -> v1
// 2 -> v2
void bfs(int n){
	queue<int> q; q.push(n), visited[n] = 1;
	color[n] = 1;
	while(!q.empty()){
		int e = q.front(); q.pop();
		//cout <<"[ "<< e << " " << color[e] << " ]";
		// Color Neighbours with diffrent color
		for(auto i=G[e].begin(); i!=G[e].end(); i++){
			if(!visited[*i]){
				q.push(*i), visited[*i] = 1;
			}
			if(color[*i] == color[e])
				f=1;
			else
				color[*i] = (color[e] == 1 ? 2 : 1);
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i=1, x, y; i<=m; i++){
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	bfs(1);
	if(f)
		cout << "No";
	else
		cout << "Yes";
}
