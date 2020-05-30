/*
    Author - Devesh
    Problem - TDPRIMES(SPOJ)
    *** OPTIMIZED VERSION ***
    Time - 0.48s
    *** Mark out all even integers beforehand ***
    *** SKIP EVERY EVEN MULTIPLE IN INTERATION ***
    start from i=3 and do i+=2 and in the inner loop iterate over odd multiple only -> odd + odd = odd and even + odd = odd
*/
#include <bits/stdc++.h>
using namespace std;
const int si = 100000000;
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

