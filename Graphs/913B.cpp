/*
	Author - Devesh
	Problem - 913B - Christmas Spruce CodeForces
*/
#include<bits/stdc++.h>
using namespace std;
int n, visited[1002], f = 0;
vector<int> T[1002], v;
void bfsM(int n){
	queue<int> q; q.push(n), visited[n] = true;
	while(!q.empty()){
		int e = q.front(), c = 0, inside = 0; q.pop();
	//	cout << e << " ";
		for(auto i=T[e].begin(); i!=T[e].end(); i++){
			if(!visited[*i])
				q.push(*i), visited[*i] = true;
			if(T[*i].empty())
				c++;
			inside = 1;
		}
		if(inside and c < 3)
			f=1;
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
	bfsM(1);
	if(f)
		cout << "No";
	else
		cout << "Yes";
}
