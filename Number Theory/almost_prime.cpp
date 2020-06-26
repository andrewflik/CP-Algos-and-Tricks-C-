/*
	Author - Devesh
	Problem - Almost Prime (CodeForces)
*/
#include<bits/stdc++.h>
using namespace std;
//const int maxn = 3005;
void sieve(int n, vector<set<int>> &aP){
	vector<bool> p(n, true);
	p[0] = p[1] = false;
	for(int i=2; i<=n; i++){
		if(p[i]){
			aP[i].insert(i);
			for(int j=i+i; j<=n; j+=i)
				p[j] = false, aP[j].insert(i);
		}
	} 
}
int main(){
	int n, s = 0;
	cin >> n;
	vector<set<int>> aP(n+n);
	sieve(n, aP);
	for(int i=2; i<=n; i++){
		if(aP[i].empty()) continue;
		if(aP[i].size() == 2){
			s++;
		}
	}
	cout << s << endl;
}
