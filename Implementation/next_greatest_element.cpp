/*
	Author - Devesh
	Problem - Next Greatest Element (GeeksForGeeks/HackerRank)
	Time Complexity - O(n)
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main(){
	int n;
	cin >> n;
	int ar[n];
	vector<pii> v(n);
	for(int i=0; i<n; i++) cin >> ar[i];
	stack<pii> s;
	for(int i=0; i<n; i++){
		if(i == 0){
			s.push({ar[i], i}); continue;
		}
		if(s.top().first < ar[i]){
			while(!s.empty() and s.top().first < ar[i]){
				pii e = s.top();
				v[e.second] = {e.first, ar[i]};
				s.pop();
			}
			s.push({ar[i], i});
		}
		else
			s.push({ar[i], i});
	}
	for(int i=0; i<n; i++)
		if(v[i].first == 0 and v[i].second == 0)
			v[i].first = v[i].second = ar[i];

	for(auto x: v)
		cout << x.first << " " << x.second << endl;
}
