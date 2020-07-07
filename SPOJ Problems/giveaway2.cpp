/*
	Problem - Giveaway (SPOJ/CODECHEF)
	Author - Devesh
	Technique - SQRT DECOMP
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5*1e5+1;
int n, bs, q, ar[maxn];
vector<int> s[1000];
int query(int s, int e, int k){
	// Left
	int i, res = 0, c;
	for(i=s; i<=e; ){
		if(i%bs == 0 and i+bs<=e){
			// Work on set
			res += ::s[i/bs].end() - lower_bound(::s[i/bs].begin(), ::s[i/bs].end(), k);
			i += bs;
		}
		else{
			// Work on array
			if(ar[i] >= k)
				res++;
			i++;
		}
	}
	return res;
}
int query2(int s, int e, int k){
	int res = 0, bl = s/bs, br = e/bs;
	if(bl == br){
		for(int i=s; i<=e; i++)
			if(ar[i] >= k) res++;
		return res;
	}
	// Cover left
	int i, j, p;
	for(i=s; i<=e and i<(bl+1)*bs; i++)
		if(ar[i] >= k) res++;
	// Cover inbetween blocks
	for(j=(bl+1)*bs; j<=e and j+bs<=e; j+=bs)
		res += ::s[j/bs].end() - lower_bound(::s[j/bs].begin(), ::s[j/bs].end(), k);
	if(j > e) j-=bs;
	// Cover the rest right
	for(p=j; p<=e; p++)
		if(ar[p] >= k) res++;
	return res;	
}
void update(int idx, int val){
	int blockNumber = idx / bs;
    int initial_val=ar[idx];
    vector<int>::iterator iter;
    ///  finding the position of idx , by its value
    iter=lower_bound(s[blockNumber].begin(),s[blockNumber].end(), initial_val);
    int pos=iter-s[blockNumber].begin();
    s[blockNumber][pos]=val;
    sort(s[blockNumber].begin(),s[blockNumber].end());///sort again, as value has been changed
    ar[idx]=val;
}
int32_t main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin >> n;
	bs = (int)sqrt(n);
	for(int i=0; i<n; i++){
		cin >> ar[i];
		s[i/bs].push_back(ar[i]);
	}
	for(int i=0; i<bs; i++)
		sort(s[i].begin(), s[i].end());
	cin >> q;
	while(q--){
		int k, a, b, c;
		cin >> k;
		if(k==0){
			cin >> a >> b >> c;
			--a, --b;
			cout << query2(a, b, c) << endl;		
		}else{
			cin >> a >> b;
			update(--a, b); ar[a] = b;
			//for(int i=0; i<n; i++) cout << ar[i] << " ";
		}
	}
}

