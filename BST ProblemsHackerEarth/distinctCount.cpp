// Distinct Count
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, x;
		cin >> n >> x;
		set<int> s;
		int k;
		for(int i=0; i<n; i++){
			cin >> k;	s.insert(k);
		}
		int AB = s.size();
		if(AB == x)
			cout << "Good\n";
		else if(s.size() < x)
			cout << "Bad\n";
		else
			cout << "Average\n";
	
	}	
	return 0;
}
