/*
	Author - Devesh
	Problem - Party(115-A) CodeForces
*/
#include<bits/stdc++.h>
using namespace std;
int n, visited[200001], f=0;
vector<int> T[200001], v;
void dfs(int n, int x){
	if(n == x) f=1;
	if(visited[n]) return;
	visited[n] = true;
	for(auto i:T[n]){
		dfs(i, x);
		if(f){
			v.push_back(n);
			return;
		}
	}
}
int main(){
	memset(visited, false, sizeof(visited));
	cin >> n;
	for(int i=2, x; i<=n; i++){
		cin >> x;
		T[x].push_back(i);
	//	T[i].push_back(x);
	}
	dfs(1, n);
	reverse(v.begin(), v.end());
	for(auto i:v)
		cout << i << " ";
	cout << n;
}
