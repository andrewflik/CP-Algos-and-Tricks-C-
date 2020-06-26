/*
	Author - Devesh
	Problem - ABA12D (SPOJ)
*/
#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int maxn = 1e6+17;
int p[maxn], pre[maxn];
void sieve(){
	for(int i=2; i<maxn; i++)
		p[i] = i;
	for(int i=2; i<maxn; i++){
		if(p[i] == i){
			for(int j=i*2; j<maxn; j+=i){
				if(p[j] != j) p[j] = -1; // Not Prime
				else p[j] = i;
			}
		}
	}
}
int checkDivSum(int n, int c){
	// Prime
	if(n==c){
		return n+1;
	}
	int ans = ((int)((n*c) - 1)/(c-1));
	// Check if ans if prime
	if(ans <= maxn)
		return ans;
	if(ans%2 == 0 || ans % 3 == 0) return 6;
	for(int i=2; i<=sqrt(ans); i+=3){
		while(ans%i==0) ans /= i;
	}
	return ans;
}
void solve(){
	pre[0] = 0, pre[1] = 0;
	// Pass II
	for(int i=2; i<maxn; i++){
		if(p[i]!=-1){
			int n = checkDivSum(i, p[i]);
			if(p[n] == n) // If prime
				pre[i] = 1;
			else
				pre[i] = 0;
		}
		else{
			pre[i] = 0;
		}
	}
	for(int i=2; i<maxn; i++)
		pre[i] += pre[i-1];
}
int32_t main(){
	sieve();	// Pass I
	solve();	// Pass II
	//for(int i=2; i<=20; i++)
	//	cout << i << " : " << p[i] << endl;
	int a, b, t;
	cin >> t;
	while(t--){
		cin >> a >> b;
		cout << pre[b] - pre[a-1] << endl;
	}
}
