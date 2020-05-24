/*
   Author - Devesh
   Problem - Maximum prefix-sum for a given range
   Link - https://www.geeksforgeeks.org/maximum-prefix-sum-given-range/
   Time Complexity - O(nlogn)
   Topic - Segment Tree
*/
#include<bits/stdc++.h>
using namespace std;
pair<int, int> tree[10000005];
void build(int cn, int *a, int l, int r){
	if(l == r){
		tree[cn].first = a[l];	// Store sum Prefix
		tree[cn].second = a[l];	// Max prefix sum in second
		return;
	}
	int mid = (l+r)/2;
	build(cn*2, a, l, mid);
	build(cn*2+1, a, mid+1, r);
	tree[cn].first = tree[cn*2].first + tree[cn*2+1].first;
	tree[cn].second = max(tree[cn*2].second, tree[cn*2].first + tree[cn*2+1].second);
}
pair<int, int> query(int cn, int l, int r, int ql, int qr){
	// Out of Range
	if(l > qr || r < ql)
		return {0, 0};
	// Inside Range
	if(l >= ql && r <= qr)
			return tree[cn];
	int mid = (l+r)/2;
	auto a = query(cn*2, l, mid, ql, qr);
	auto b = query(cn*2+1, mid+1, r, ql, qr);
	pair<int, int> c = {a.first + b.first, max(a.second, a.first + b.second)};
	return c;
}
int main(){
	int n, q;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];
	build(1, a, 0, n-1);
	// Answer some queries
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		auto a = query(1, 0, n-1, l, r);
		cout << a.second << endl;
	}
}
