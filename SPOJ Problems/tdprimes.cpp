/*
    Author - Devesh
    Problem - TDPRIMES(SPOJ)
    *** NON OPTIMIZED VERSION***
    Time - 1.14s
*/

#include <iostream>
#include <vector>
using namespace std;
const int si = 1e8;
bool primes[si];
vector<int> f;
void sieve(){
	fill(primes, primes+si, true);
	primes[0] = primes[1] = false;
	for(int i=2; i<10000; i++){
		if(primes[i]){
			for(int j=i+i; j<si; j+=i)
				primes[j] = false;
		}
	}
	f.push_back(2);
	for(int i=3; i<si; i+=2)
		if(primes[i])
			f.push_back(i);
	for(int i=0; i<f.size(); i+=100)
		cout << f[i] << "\n";
}
int main() {
	sieve();
	return 0;
}

