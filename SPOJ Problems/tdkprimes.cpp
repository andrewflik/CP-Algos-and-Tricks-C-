#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
bool p[maxn];
//int ar[5000001];
void sieve(){
	fill(p, p+maxn, true);
    p[0] = p[1] = false;
    for(int i=2; i<sqrt(maxn); i++){
        if(p[i]){
            for(int j=i+i; j<maxn; j+=i)
                p[j] = false;
        }
    }
    // int k = 1;
    // ar[k] = 2;
    // for(int i=3; i<maxn; i+=2)
    //     if(p[i]) ar[++k] = i;
}
int main(){
    sieve();
    // int t;
    // cin >> t;
    // while (t--){
    //     int n;
    //     cin >> n;
    //     //cout << ar[n] << "\n";
    // }
}