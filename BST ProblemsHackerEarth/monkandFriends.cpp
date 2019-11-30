// HackerEarth Proble
// Monk watching the fight (BST)
#include<bits/stdc++.h>
using namespace std;

// GCC OPTIMIZATION
/*-------------------------*/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
/*-------------------------*/
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long int


int main(){
    IO
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		unordered_set<ll> s; ll a;
		for(int i=0; i<n; i++){
		    cin >> a;
		    s.insert(a);
		}
		for(int i=0; i<m; i++){
		    cin >> a;
		    if(s.find(a)!=s.end())
		        cout << "YES\n";
		    else{
		        s.insert(a);
		        cout << "NO\n";
		    }
		}
	}
	return 0;
}
