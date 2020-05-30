/*
    Author - Devesh
    Problem - TDPRIMES(SPOJ)
    *** NON OPTIMIZED VERSION***
    Time - 1.14s
*/

#include <bits/stdc++.h>
using namespace std;
const int si = 10001;
vector<bool> v(si, true);
vector<int> primes;
void sieve(){
	// Mark out all even integers
	for(long j=4; j<=si; j+=2)
		v[j] = false;
	
	v[0] = v[1] = false;
	for(long i=3; i<=sqrt(si); i+=2){
		if(v[i]){
			for(long j=i*i; j<=si; j=j+(i*2))
				v[j] = false;
		}
	}
	primes.push_back(2);
	for(long i=3; i<si; i+=2)
		if(v[i])
			primes.push_back(i);
	for(long i=0; i<primes.size(); i+=100)
		cout << primes[i] << "\n";
}
int main() {
	sieve();
	return 0;
}

