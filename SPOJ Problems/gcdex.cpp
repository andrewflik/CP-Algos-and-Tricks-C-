/*
	Author - Devesh
	Problem - GCDEX (SPOJ)
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000002;
long long phi[maxn], r[maxn];
void Phi(){
	phi[0] = 0, phi[1] = 1;
	for(int i=1; i<maxn; i++)
		phi[i] = i;
	for(int i=2; i<maxn; i++){
		if(phi[i] == i){
			for(int j=i; j<maxn; j+=i)
				phi[j] -= phi[j]/i;
		}
	}
  
  /* Lemma : If d is a divisor of n, then there are Phi(n/d) numbers i <= n for which gcd(i,n)=d */
  
	for(int i=1; i<maxn; i++)
		for(int j=i+i; j<maxn; j+=i)
			r[j] = r[j] + 1LL*i*phi[j/i];
	
	// Pre-process
	for(int i=2; i<maxn; i++)
		r[i] += r[i-1];
}
int main(){
	Phi();
	int n;
	while(cin >> n and n){
		cout << r[n] << endl;
	}
}
