/*
    Author - Devesh
    Topic - Matrix Expo
	Time Complexity - O(n^3*log(n))
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll mat[2], f[2][2];
ll ans[2][2], fn[2];
ll solve(ll p){
	--p;	// Take Care Of This .............

	ll res[2][2], t1[2][2], t2[2][2];
	// Init as Identity Matrix
	res[0][0] = 1, res[0][1] = 0;
	res[1][0] = 0, res[1][1] = 1;
	while(p){
		if(p&1){	// For every set bit store the results
			// R *= F
			ans[0][0] = (res[0][0] * f[0][0]) % mod + (res[0][1] * f[1][0]) % mod;
			ans[0][1] = (res[0][0] * f[0][1]) % mod + (res[0][1] * f[1][1]) % mod;
			ans[1][0] = (res[1][0] * f[0][0]) % mod + (res[1][1] * f[1][0]) % mod;
			ans[1][1] = (res[1][0] * f[0][1]) % mod + (res[1][1] * f[1][1]) % mod;
			// Copy ans back to indentity
			res[0][0] = ans[0][0], res[0][1] = ans[0][1];
			res[1][0] = ans[1][0], res[1][1] = ans[1][1];
		}
		// F *= F
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++)
				t1[i][j] = t2[i][j] = f[i][j];

		f[0][0] = (t1[0][0] * t2[0][0]) % mod + (t1[0][1] * t2[1][0]) % mod;
		f[0][1] = (t1[0][0] * t2[0][1]) % mod + (t1[0][1] * t2[1][1]) % mod;
		f[1][0] = (t1[1][0] * t2[0][0]) % mod + (t1[1][1] * t2[1][0]) % mod;
		f[1][1] = (t1[1][0] * t2[0][1]) % mod + (t1[1][1] * t2[1][1]) % mod;
		
		p = p >> 1;
	}
	fn[0] = (ans[0][0] * mat[0]) % mod + (ans[0][1] * mat[1]) % mod;
	fn[1] = (ans[1][0] * mat[0]) % mod + (ans[1][1] * mat[1]) % mod;
	return fn[1];
}
ll nthFib(ll n){
	// Matrix Init
	f[0][0] = 1, f[0][1] = 1;
	f[1][0] = 1, f[1][1] = 0;
	// Base Cases Init
	mat[0] = 1, mat[1] = 0;
	return solve(n);
}
int main(){
	cout << nthFib(100) << endl;
}
