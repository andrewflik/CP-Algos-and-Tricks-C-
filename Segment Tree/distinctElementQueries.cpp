/*
	Author - Devesh 
	Problem - https://www.geeksforgeeks.org/queries-number-distinct-elements-subarray/
	Time Complexity - O(nlogn)
	Topic - Segment Tree
*/
#include<bits/stdc++.h>
#define DEBUG cout << " Debug \n ";
using namespace std;
vector<set<int>> v(1000);
void build(int cn, int *ar, int l, int r){
	if(l == r){
		v[cn].insert(ar[l]);
		return;
	}
	int mid = (l+r)/2;
	build(cn*2, ar, l, mid);
	build(cn*2+1, ar, mid+1, r);
	v[cn].insert(v[cn*2].begin(), v[cn*2].end());
	v[cn].insert(v[cn*2+1].begin(), v[cn*2+1].end());	
} 
set<int> query(int cn, int l, int r, int ql, int qr){
	set<int> res, a, b;
	// Out of Range
	if(l > qr || r < ql)
		return a;
	// Inside Range
	if(l >= ql && r <= qr)
		return v[cn];
	a = query(cn*2, l, (l+r)/2, ql, qr);
	b = query(cn*2+1, (l+r)/2 + 1, r, ql, qr);
	res.insert(a.begin(), a.end());
	res.insert(b.begin(), b.end());
	return res;
}
int main(){
	int n, q;
	cin >> n;
	int ar[n];
	for(int i=0; i<n; i++)
		cin >> ar[i];
	build(1, ar, 0, n-1);
	//DEBUG
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		cout << query(1, 0, n-1, l, r).size() << endl;
	}
}
