/*
    Author - Devesh
    Problem - HS08PAUL (SPOJ)
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int s = 1e7+1;
vector<bool> v(10001, true);
vector<int> primes;
int pre[s];
void sieve(){
	v[0] = v[1] = false;
	for(int i=4; i<=10000; i+=2)
		v[i] = false;
	for(int i=3; i<=100; i+=2){
		if(v[i]){
			for(int j=i*i; j<=10000; j+=(2*i))
				v[j] = false;
		}
	}
	primes.push_back(2);
	for(int i=3; i<=10000; i+=2)
		if(v[i])
			primes.push_back(i);
//	for(int i=0; i<=100; i++)
//		cout << primes[i] << endl;
}
bool isPrime(int n){
	for(auto x: primes){
		if(x*x > n)
			break;
		if(n%x == 0)
			return false;
	}
	return true;
}
void init(){
	// Preprocessing every prime
	for(ll i=1; i*i<=s; i++){
		for(ll j=1; (j*j*j*j+i*i)<=s; j++){
			if(isPrime(i*i+j*j*j*j))
				pre[i*i+j*j*j*j] = 1;
		}
	}
 
	for(int i=1; i<=s; i++)
		pre[i] += pre[i-1];
}
int main(){
	memset(pre, 0, sizeof(pre));
	sieve();
	init();
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << pre[n] << endl;
	}
}
