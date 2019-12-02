// UnDirected Graph Implementation
// with BFS & DFS
// ~CP
#include<bits/stdc++.h>
using namespace std;
const int si = 1e6+5;
bool visited[si] = {false};

void DFS(int **edges, int totalVertex, int n){
	cout << n << " ";
	visited[n] = true;
	for(int i=1; i<=totalVertex; i++){
		if(n == i)
			continue;
		if(edges[n][i] == 1){
			if(visited[i] == true)
				continue;
			DFS(edges, totalVertex, i);
		}
	}
}
void BFS(int **edges, int totalVertex, int n){
	bool vis[n] = {false};
	queue<int> q;
	q.push(n);
	vis[n] = true;
	while(!q.empty()){
		int frontEle = q.front();	q.pop();
		cout << frontEle << " ";
		for(int i=1; i<=totalVertex; i++){
			if(edges[frontEle][i] == 1 && !vis[i]){
				q.push(i);
				vis[i] = true;
			}
		}
	}	
}
void addEdge(int x, int y, int **edges){
	edges[x][y] = 1;
	edges[y][x] = 1;
}
int main(){
	int totalVertices = 6;
	int **edges = new int *[totalVertices+1];
	for(int i=0; i<=totalVertices; i++){	
		edges[i] = new int[totalVertices+1];
		memset(edges[i], -1, sizeof(edges[i]));
	}
	addEdge(1, 2, edges);
	addEdge(1, 4, edges);
	addEdge(3, 4, edges);
	addEdge(3, 2, edges);
	addEdge(4, 5, edges);
	addEdge(3, 5, edges);
	addEdge(4, 5, edges);
	addEdge(5, 6, edges);
	addEdge(3, 6, edges);
	DFS(edges, totalVertices, 1);
	cout << endl;
	BFS(edges, totalVertices, 1);
	return 0;
}
