/*
	Author - Devesh
	Topic - SEGMENT TREE
	Problem - RMQ (Range Minimum Query)
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+17;
int a[maxn], n, q, l, r, blockSize;
char res;
vector<int> t(maxn);
void build(int cn, int l, int r){
	if(l == r){
		t[cn] = a[l];
		return;
	}
	int m = (l+r)/2;
	build(cn*2, l, m);
	build(cn*2+1, m+1, r);
	t[cn] = min(t[cn*2], t[cn*2+1]);
}
void update(int cn, int l, int r, int val, int index){
	if(l == r){
		t[cn] = val, a[index] = val;
		return;
	}
	int mid = (l+r)/2;
	if(index <= mid)
		update(cn*2, l, mid, val, index);
	else
		update(cn*2+1, mid+1, r, val, index);
	t[cn] = min(t[cn*2], t[cn*2+1]);
}
int query(int cn, int l, int r, int ql, int qr){
	// Out of range
	if(ql > r or l > qr)
		return INT_MAX;
	// Inside of range
	if(l >= ql and r <= qr)
		return t[cn];

	int mid=(l+r)/2;
	return min(query(cn*2, l, mid, ql, qr), query(cn*2+1, mid+1, r, ql, qr));
}
int main(){
	cin >> n >> q;
	for(int i=0; i<n; cin>> a[i], i++);
		build(1, 0, n-1);
	while(q--){
		cin >> res >> l >> r;
		if(res == 'q')
			cout << query(1, 0, n-1, --l, --r) << endl;
		else
			update(1, 0, n-1, r, --l);
	}
}

