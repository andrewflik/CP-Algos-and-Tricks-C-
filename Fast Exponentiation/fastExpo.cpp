// Fast Exponentiation
// Time Complexity : O(logn)
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

// Recursive Method
ll fastExpoRec(ll n, ll p){
	// Base case
	if(p == 1)
		return n;
	
	ll res = fastExpoRec(n, p/2);
	
	if(p&1)
		return res*res*n;	// For that one extra n that gets left out
	else
		return res*res;	
}

// Iterative Method
ll fastExpo(ll n, ll p){
	ll res = 1;	// Long long as to avoid integer overflow
	while(p > 0){
		if(p&1)	//If the bit is set '1'
			res *= n;
		n *= n;
		p >>= 1;	
	}
	return res;
}
int main(){
	cout << fastExpo(2, 12) << endl;
	cout << fastExpoRec(2, 12) << endl;
}
