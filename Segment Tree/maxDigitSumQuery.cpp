/*
   Author - Devesh
   Problem - Range Queries to find the Element having Maximum Digit Sum
   Link - https://www.geeksforgeeks.org/range-queries-to-find-the-element-having-maximum-digit-sum/?ref=rp
   Time Complexity - O(nlogn)
   Topic - Segment Tree
*/
#include<bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>
using namespace std;
pair<int, int> tree[10000005];
int digitSum(int n){
	int sum = 0;
	while(n){
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
pii cmp(pii a, pii b){
	if(a.second > b.second)
		return a;
	else if(a.second < b.second)
		return b;
	else
		return a.first > b.first ? a : b;
}
void build(int cn, int *a, int l, int r){
	if(l == r){
		tree[cn].f = a[l];	// Store actual Number
		tree[cn].s = digitSum(a[l]);	// Store digitSum
		return;
	}
	int mid = (l+r)/2;
	build(cn*2, a, l, mid);
	build(cn*2+1, a, mid+1, r);
	tree[cn] = cmp(tree[cn*2], tree[cn*2+1]);
}
pii query(int cn, int l, int r, int ql, int qr){
	// Out of Range
	if(l > qr || r < ql)
		return {0, 0};
	// Inside Range
	if(l >= ql && r <= qr)
			return tree[cn];
	int mid = (l+r)/2;
	auto a = query(cn*2, l, mid, ql, qr);
	auto b = query(cn*2+1, mid+1, r, ql, qr);
	return cmp(a, b);
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
		cout << query(1, 0, n-1, l, r).first << endl;
	}
}
