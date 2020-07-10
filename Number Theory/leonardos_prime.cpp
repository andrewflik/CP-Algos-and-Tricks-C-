/*
	Author - Devesh
	Probem - Leonardo's Prime (HackerRank)
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 50;
bool primes[maxn];
vector<ll> f;
void sieve(){
	fill(primes, primes+maxn, true);
	for(int i=4; i<maxn; i+=2)
		primes[i] = false;
	primes[1] = false;
	f.push_back(2);
	for(int i=3; i<maxn; i+=2){
		if(primes[i]){
			f.push_back(i);
			for(int j=i*2; j<maxn; j+=i)
				primes[j] = false;
		}
	}
	// Preprocess
	for(int i=1; i<f.size(); i++)
		f[i] *= f[i-1];
}
int main(){
	sieve();
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout << upper_bound(f.begin(), f.end(), n) - f.begin() << endl;
	}
}
