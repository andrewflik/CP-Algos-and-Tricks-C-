// Help Ashu - HackerEarth
// Segment Tree Problem
#include<bits/stdc++.h>
using namespace std;
// Odd - Even
vector<pair<int, int>> tree(500005);
int ar[500005];
void build(int cn, int ar[], int l, int r){
	if(l == r){
		if(ar[l])
			tree[cn].first = 1, tree[cn].second = 0;
		else
			tree[cn].first = 0, tree[cn].second = 1;
		return;
	}
	int mid = (l+r)/2;
	build(cn*2, ar, l, mid);
	build(cn*2+1, ar, mid+1, r);
	
	tree[cn].first = tree[cn*2].first + tree[cn*2+1].first;
	tree[cn].second = tree[cn*2].second + tree[cn*2+1].second;
}
void update(int cn, int ar[], int l, int r, int p, pair<int, int> val){
	if(l == r){
		if(tree[cn].first != val.first && tree[cn].second != val.second)
			swap(tree[cn].first, tree[cn].second);
        return;
	}
	int mid = (l+r)/2;
	if(p > mid)	// Right
		update(cn*2+1, ar, mid+1, r, p, val);
	else
		update(cn*2, ar, l, mid, p, val);
	
	tree[cn].first = tree[cn*2].first + tree[cn*2+1].first;
	tree[cn].second = tree[cn*2].second + tree[cn*2+1].second;

}
pair<int, int> query(int cn, int l, int r, int ql, int qr){
	// Out of Range
	if(qr < l || ql > r)
		return {0, 0};
	// Inside Range
	if(ql <= l && qr >= r)
        return tree[cn];

	int mid = (l+r)/2;
	pair<int, int> p1 = query(cn*2, l, mid, ql, qr);
	pair<int, int> p2 = query(cn*2+1, mid+1, r, ql, qr);
	return {p1.first + p2.first, p2.second + p1.second};
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, q;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> ar[i];
		if(ar[i]&1)
			ar[i] = 1;
		else
			ar[i] = 0;
	}
	build(1, ar, 0, n-1);
	cin >> q;
	while(q--){
		int k, x, y;
		cin >> k >> x >> y;
		if(k == 0){
			// Modify index i to x
            pair<int, int> v(0, 0);
            if(y&1)
                v.first = 1;
            else
                v.second = 1;
			update(1, ar, 0, n-1, x-1, v);
		}
		else if(k == 1){
			// Count Even
			cout << query(1, 0, n-1, x-1, y-1).second << endl;
		}
		else{
			// Count Odd
			cout << query(1, 0, n-1, x-1, y-1).first << endl;
		}
	}
}
