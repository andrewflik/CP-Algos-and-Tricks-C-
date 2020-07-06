/*
	Problem - GIVEAWAY (SPOJ)/(CodeChef)
	Author - Devesh
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

//#define ll long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> pds;

const int maxn = 5*1e5;
int ar[maxn], n, q;
pds T[2*maxn];

pds merge_(pds m1, pds m2){
	pds m(m1.begin(), m1.end());
	for(auto it:m2)
		m.insert(it);
//	for(auto x:m)
//		cout << x.first << " " << x.second << endl;
	return m;
}
void build(int cn, int s, int e){
	if(s==e){
		T[cn].insert(ar[s]);
		return;
	}
	int m = s+(e-s)/2;
	build(cn*2, s, m);
	build(cn*2+1, m+1, e);
	T[cn] = merge_(T[cn*2], T[cn*2+1]);
}
int query(int cn, int s, int e, int ql, int qr, int k){
	// Out of range
	if(ql > e or s > qr) return 0;
	// Inside range
	if(s >= ql and e <= qr) 
		return T[cn].size() - T[cn].order_of_key(k);
	int m = s+(e-s)/2;
	return query(cn*2, s, m, ql, qr, k) + query(cn*2+1, m+1, e, ql, qr, k);
}
void update(int cn, int s, int e, int oval, int indexOval, int val){
	if(s == e){
		ar[indexOval] = val;
		T[cn].erase(oval);	// Erase old ele
		T[cn].insert(val);
		return;
	}
	int m = s+(e-s)/2;
	if(indexOval <= m)	// Left
		update(cn*2, s, m, oval, indexOval, val);
	else
		update(cn*2+1, m+1, e, oval, indexOval, val);
	T[cn].erase(T[cn].find(oval));
	T[cn].insert(val);
}
int32_t main(){	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++) cin >> ar[i];
	build(1, 0, n-1);
	cin >> q;
	while(q--){
		int k, a, b, c;
		cin >> k;
		if(k == 0){
			cin >> a >> b >> c;
			cout << query(1, 0, n-1, --a, --b, c) << endl;
		}
		else{
			cin >> a >> b; --a;
			update(1, 0, n-1, ar[a], a, b);
		}
	}
}



