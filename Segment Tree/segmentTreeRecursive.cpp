/* 		Recursive Implementation of Segment Tree
 	Update - O(logn)
 	Query - O(logn)
*/
#include<bits/stdc++.h>
using namespace std;

const int size = 1e5;
int ar[size];
int tree[size * 2];
int n;
// Building the segment tree
void build(int node, int *ar, int s, int e){
	// Base Case
	if(s == e){
		tree[node] = ar[s];
		return;
	}
	if(e > s){
		int m = (s+e)/2;
		build(node*2, ar, s, m);
		build(node*2+1, ar, m+1, e);
		tree[node] = tree[node*2] + tree[node*2+1];
	} 
}
// Modifying element in array and updating the tree
void update(int node, int val, int index, int s, int e){
	if(s == e){
		// Update the tree node and return
		ar[index] = val;
		tree[node] = val;
		return;
	}

	int m = (s+e)/2;
	if(index > m)
		update(node*2+1, val, index, m+1, e);
	else
		update(node*2, val, index, s, m);
	// Update the parent node
	tree[node] = tree[node*2] + tree[node*2+1];
}
// Query over the tree
int query(int node, int s, int e, int ql, int qr){
	// Completely Inside
	if(ql <= s &&  qr >= e)
		return tree[node];
	// Completely Outside
	if(qr < s || ql > e)
		return 0;

	int m = (s+e)/2;
	return query(node*2, s, m, ql ,qr) + query(node*2+1, m+1, e, ql ,qr);
}
int main(){
	cin >> n;
	for(int i=0; i<n; cin >> ar[i], i++);
	//for(int i=0; i<n; cout << ar[i] << " ", i++);
	build(1, ar, 0, n-1);
	for(int i=0; i<2*n-1; cout << tree[i] << " ", i++);
	cout << endl;
	update(1, 10, 4, 0, n-1);
	for(int i=0; i<2*n-1; cout << tree[i] << " ", i++);
	cout << endl;
	// Queries
	cout << query(1, 0, n-1, 0, 2) << endl;
	cout << query(1, 0, n-1, 1, 2) << endl;
	cout << query(1, 0, n-1, 2, 2) << endl;
	cout << query(1, 0, n-1, 2, 4) << endl;
	return 0;
}
