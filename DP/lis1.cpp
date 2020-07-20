/*
	Author - Devesh
	Problem - LIS
	Application - Dynamic Programming
	Time Complexity - O(n^2)
*/
#include<bits/stdc++.h>
using namespace std;
int lis(vector<int> &ar, int n){
	int dp[n], ans = 1;
	fill(dp, dp+n, 1); // Every element is LIS of len 1 
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(ar[j] < ar[i])
				dp[i] = max(dp[j]+1, dp[i]);
		}
	}
	for(int i=0; i<n; i++)
		ans = max(ans, dp[i]);
	return ans;
}
int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	cout << lis(v, n);
}
