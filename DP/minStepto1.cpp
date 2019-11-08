// Min Step to 1 Problem
#include<bits/stdc++.h>
using namespace std;
// Recursive Naive Solution
int minStepto1(int n){
	// BASE CASE
	if(n==1)
		return 0;

	int res = 1 + minStepto1(n-1);
	if(n%3 == 0)
		return min(res, 1 + minStepto1(n/3));
	if(n%2 == 0)
		return min(res, 1 + minStepto1(n/2));

	return res;
}
// Memoized Solution
int ar[100000];
int minStepto1D(int n){
	// Base Case
	if(n==1)
		return 0;
	if(ar[n]!=-1)
		return ar[n];

	int res = 1 + minStepto1(n-1);
	if(n%3 == 0)
		res = min(res, 1 + minStepto1(n/3));
	if(n%2 == 0)
		res = min(res, 1 + minStepto1(n/2));
	ar[n] = res;
	return res;
}
int dp[100005];
// Bottom Up Approach
int minStepto1I(int n){
	// Base Case
	dp[0] = dp[1] = 0;
	dp[2] = dp[3] = 1;
	for(int i=4; i<=n; i++){
		int ans1=INT_MAX, ans2=INT_MAX, ans3;
		ans3 = dp[i-1];
		if(!(i%2))
			ans1 = dp[i/2];
		if(!(i%3))
			ans2 = dp[i/3];
		dp[i] = 1 + min(min(ans1, ans2), ans3);
	}
	return dp[n];
}
int main(){
	cout << minStepto1(7) << endl;
	memset(ar, -1, sizeof(ar));
	cout << minStepto1D(7) << endl;
	cout << minStepto1I(7) << endl;
}
