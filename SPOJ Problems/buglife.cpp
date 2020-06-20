/*
	Author - Devesh
	Problem - BUGLIFE(SPOJ)
	Link - https://www.spoj.com/problems/BUGLIFE/
*/
#include<bits/stdc++.h>
using namespace std;
int n, m, visited[2001], color[2001], f=0;
vector<int> G[2001];
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
void reset(){
	f = 0;
	memset(visited, 0, sizeof(visited));
	memset(color, 0, sizeof(color));
	for(auto &i:G)
		i.clear();
}
void bfsc(int n){
	for(int i=1; i<=n; i++){
		if(!visited[i])
			bfs(i);
	}
}
int main(){
	int t;
	cin >> t;
	for(int k=1; k<=t; k++){
		cin >> n >> m;
		for(int i=1, x, y; i<=m; i++){
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		bfsc(n);
		cout << "Scenario #"<< k << ":" << endl;
		if(!f)
			cout << "No suspicious bugs found!" << endl;
		else
			cout << "Suspicious bugs found!" << endl;
		reset();
	}
}
