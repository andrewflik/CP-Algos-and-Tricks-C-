#include<bits/stdc++.h>
using namespace std;
#define MOD			1000000007
#define lli 		long long
#define li 			long 
#define pi 			pair<int, int>
#define pl 			pair<li, li>
#define pll 		pair<lli, lli>
#define vi 			vector<int>
#define vl 			vector<li>
#define vll 		vector<lli>
#define vpi			vector<pi>
#define vpl			vector<pl>
#define vpll 		vector<pll>

// Hash Map
#define hash(x, y)	unordered_map<x, y> hash
// Saving states
#define states(x)	set<x> states

#define pb			push_back
#define rep(x, n)	for(int i=(x); i<(n); i++)
#define per(x, n)	for(int i=(n); i>(x); i--)
#define BEmin(x)	x.begin(), x.end()
#define BEmax(x)	x.begin(), x.end(), greater<int>()
#define L(x)		x.length()


// 1. Sieve of Eratosthenes
// 2. Prime Factorization -> Trial Division - Wheel Factorization (More to come)
// 3. Euler Toient Function

const int maxSize = 1e7+9;
vi primes;
vi factors;
bool temp[maxSize];
int sp[maxSize];	// Store smallest prime
int phi[maxSize];	// Store coprimes 
void sieve(){	// Use li to avoid seg fault
	fill(temp, temp+maxSize, true);
	for(li i=2; i<=maxSize; i++){	// Dont sieve till root
		if(temp[i]){			// If you want to store 
			sp[i] = i;			// the smallest prime
			for(li j=i*i; j<=maxSize; j+=i)
				temp[j] = false, sp[j] = (sp[j]) ? sp[j] : i;
		}
	}
}
void primeFactors(int n){
	while(!(n&1))
		n = n >> 1, factors.pb(2);
	for(int i=3; i*i<=n; i+=2)	// No need to increment by 1 instead 2
		while(!(n%i))
			factors.pb(i), n/=i;
	if(n > 1)	// When the number itself is prime
		factors.pb(n);
}
void primeFactors2(int n){	// Little more optimized than the above one
	// Eliminate 2, 3, 5
	for(int x: {2, 3, 5})
		while(!(n%x))	
			factors.pb(x), n/=x;
	for(int i=7, j=0; i*i<=n; i+=7)
		while(!(n%i))
			factors.pb(i), n/=i;
	if(n > 1)
		factors.pb(n);
}
// Using sieve for prime factorization in log(n)
void primeFactors3(int n){
	while(n!=1){
		factors.pb(sp[n]);
		n /= sp[n];
	}
}
// Euler's Toient Function - O(sqrt(n))
int phi_(int n){	
	int p = n;
	while(!(n&1))
		n = n << 1;
	for(int i=2; i*i<=n; i++){
		if(n%i == 0){
			while(!(n%i))
				n /= i;
			p -= p/i;
		}
	}
	return p;	// return total coprime to n from 1 to n
}
void phi_till_n(){
	phi[0] = 0, phi[1] = 1;
	for(int i=2; i<=maxSize; phi[i] = i, i++);
	for(int i=2; i<=maxSize; i++){
		if(phi[i] == i){	// If not touched 
			for(int j=i; j<=maxSize; j+=i){
				phi[j] -= phi[j]/i;
			}
		}
	}
}
int main(){
	sieve();
	rep(2, 100){
		if(temp[i])
			cout << i << " ";
	}
	cout << endl;

	phi_till_n();
	rep(2, 100)
		cout << phi[i] << " ";

	return 0;
}
