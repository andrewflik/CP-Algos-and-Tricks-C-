/*
	Author - Devesh
	Problem - Powerful Array (CodeForces)	
	Technique - Mo's Algorithm
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 200001;
int blockSize, n, t;
long long res = 0;
vector<long long> ans(maxn);
int temp[1000001], ar[maxn];

struct Query{
	int l, r, oi;
	bool operator < (Query c) const{
		return make_pair(c.l/blockSize, c.r) > make_pair(l/blockSize, r);
	}
}q[maxn], Q;
void add(int idx){
	res -= 1LL*temp[ar[idx]]*temp[ar[idx]]*ar[idx];
	temp[ar[idx]]++;
   	res += 1LL*temp[ar[idx]]*temp[ar[idx]]*ar[idx];
}
void rem(int idx){
	res -= 1LL*temp[ar[idx]]*temp[ar[idx]]*ar[idx];
   	temp[ar[idx]]--;
	res += 1LL*temp[ar[idx]]*temp[ar[idx]]*ar[idx];
}
void solveMo(){
	sort(q, q+t);
//	for(int i=0; i<t; i++) cout << q[i].l << " " << q[i].r << endl;
	int ml = 0, mr = -1;
	for(int i=0; i<t; i++){
		while(ml > q[i].l) ml--, add(ml);
		while(mr < q[i].r) mr++, add(mr);
		while(ml < q[i].l) rem(ml), ml++;
		while(mr > q[i].r) rem(mr), mr--;
		ans[q[i].oi] = res;
	}
}
int main(){
	cin >> n >> t;
	blockSize = (int)sqrt(n);
	for(int i=0; i<n; i++) cin >> ar[i];
	for(int i=0; i<t; i++){ 
			cin >> q[i].l >> q[i].r; 
			q[i].l--, q[i].r--; 
			q[i].oi = i;
	}
	solveMo();
	for(int i=0; i<t; i++)
		cout << ans[i] << endl;
}

