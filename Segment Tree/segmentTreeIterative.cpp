// Iterative Segment Tree Implementation
#include<bits/stdc++.h>
using namespace std;

template<class t>
t fp(t n, t p){
	if(p == 1)
		return n;
	t res = 1;
	while(p){
		if(p&1)	res = res * n;
		n *= n;
		p >>= 1;
	}
	return res;
}
void build(int *t, int s, int h){
	for(int i=h-1; i>=1; i--) t[i] = t[i<<1] + t[i<<1|1];	
}
void update(int f, int *t, int index, int v){
	for(t[index+f]=v, f+=index; f>1; f>>=1)	t[f>>1] = t[f] + t[f^1];
}
int query(int f, int *t, int ql ,int qr){
	int res = 0;
	for(ql+=f, qr+=f; ql <=qr; ql>>=1, qr>>=1){
		if(ql&1) res += t[ql++];
		if(!(qr&1)) res += t[qr--];
	}
	return res;
}
int main(){
	int n;
	cin >> n;
	int h = int(ceil(log2(n)));
	int size = fp(2, h)*2;
	int firstIndex = fp(2, h);
	int tree[size];
	memset(tree, 0, sizeof(tree));
	for(int i=firstIndex; i<firstIndex+n; cin >> tree[i], i++);
	build(tree, size, firstIndex);
	for(auto x : tree)
		cout << x << " ";
	cout << endl;
	cout << query(firstIndex, tree, 1, 4) << endl;
	cout << query(firstIndex, tree, 2, 4) << endl;
	cout << query(firstIndex, tree, 3, 4) << endl;
	update(firstIndex, tree, 4, 9);
	for(auto x : tree)
		cout << x << " ";
	return 0;
}
