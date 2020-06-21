/*
	Author - Devesh
	Topic - SQRT DECOMPISTION TRICK
	Problem - RMQ (Range Minimum Query)
  Link - https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/range-minimum-query/description/
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+17;
int a[maxn], n, q, l, r, blockSize;
char res;
vector<int> blocks;
int query(int l, int r){
	--l, --r;
	int ans = INT_MAX, i;
	for(i=l; i<=r and i%blockSize!=0; i++)
		ans = min(ans, a[i]);
	for(; i+blockSize<=r and i%blockSize==0; i+=blockSize)
		ans = min(ans, blocks[i/blockSize]);
	for(; i<=r; i++)
		ans = min(ans, a[i]);
	return ans;
}
void update(int x, int y){
	// see which block x lies in
	--x;
	int blockN = x/blockSize;
	a[x] = y;
    int i=blockN*blockSize, lim;
	lim = i+blockSize-1;
	blocks[blockN] = INT_MAX; // Reset Block Min Stored
	while(i<=lim and i<n){
		blocks[i/blockSize] = min(a[i], blocks[i/blockSize]);
		++i;
	}
	//blocks[blockN] = min(blocks[blockN], y); -> cant do this
}
int prep(){
	blockSize = (int)sqrt(n);
	int len = ceil(sqrt(n+.0));
	blocks.resize(len, INT_MAX); // Create blocks of sqrt(n) size
	for(int i=0; i<n; i++)
		blocks[i/blockSize] = min(a[i], blocks[i/blockSize]);
//	for(auto x: blocks)
//		cout << x << "  ";
}
int main(){
	cin >> n >> q;
	for(int i=0; i<n; cin>> a[i], i++);
	prep();
	while(q--){
		cin >> res >> l >> r;
		if(res == 'q')
			cout << query(l, r) << endl;
		else
			update(l, r);
	}
}

