/*Traditional DP Problem
  When reptition is not allowed
*/
#include<bits/stdc++.h>
using namespace std;

const int si = 1e5;
int dp[si];
bool solved[si];
// Dynamic Approach
int countD(int ar[], int s, int n){
	if(s == 0){
		solved[s] = true;
		return 1;
	}
	if(n < 0 || s < 0)
		return 0;
	if(solved[s])	// Already have the preComputed results
		return dp[s];
	else 
		dp[s] = countD(ar, s - ar[n], n-1) + countD(ar, s, n-1);
	return dp[s];
}
// Plain Recursive Approach with T.C -> 2^n
int count(int ar[], int s, int n){
	if(s == 0)
		return 1;
	if(n < 0 || s < 0)
		return 0; 
	return count(ar, s - ar[n], n-1) + count(ar, s, n-1); 
}
int main(){
	int ar[] = {2,4,6,8};
	cout << countD(ar, 12, 2) << endl;
	cout << count(ar, 12, 2) << endl;
	return 0;
}
