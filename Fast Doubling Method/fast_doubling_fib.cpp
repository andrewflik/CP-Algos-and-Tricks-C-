  /* 
 Fast Doubling Method : Faster than Matrix Expo by some constant

 Fib Series - Derived from the relation that we found in
 Matrix expo.

	F(2n+1) = F(n+1)^2 + F(n)^2
	F(2n) = F(n)[2F(n+1) - F(n)]

These identities can be extracted from the matrix exponentiation algorithm. In a sense, this algorithm is the matrix exponentiation algorithm with the redundant calculations removed. It should be a constant factor faster than matrix exponentiation, but the asymptotic time complexity is still the same.
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
pair<ll ,ll> nthFib(ll n){
	if(n == 0)
		return {0, 1};
	auto p = nthFib(n >> 1);
	auto x = p.first * (2 * p.second - p.first);
	auto y = p.first * p.first + p.second * p.second;
	if(n&1)
		return {y, x + y};
	else
		return {x, y};
}
int main(){
	cout << nthFib(7).first << endl;
}
