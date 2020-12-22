/*
    Author - Devesh
    Problem - VECTOR8
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int pre[maxn], p[maxn];
int pow2(int p){
    if(p == 1) return 10;
    if(p == 2) return 10 * 10;
    int res = 1, n = 10;
    while(p){
        if(p&1) res *= n;
        p >>= 1;
        n *= n;
    }
    return res;
}
bool isBad(int n){
    if(n < 10)
        return true;
    int x = 0, t = n, temp = pow2(floor(log10(n)));
    while(n){
        if(n % 10 == 0) return false;
        n /= 10;
    }
    while(temp!=1){
        if(p[t % temp] == 0) return false;
        temp /= 10;
    }
    return true;
}
void sieve(){
    fill_n(p, maxn, 1);
    p[0] = p[1] = 0;
    for(int i=2; i<maxn; i++){
        if(p[i]){
            for(int j=i+i; j<maxn; j+=i)
                p[j] = 0;
        }
    }
    for(int i=2; i<maxn; i++){
        if(p[i])
            pre[i] = (int)isBad(i);
        pre[i] += pre[i-1];
    }
}
int main(){
    sieve();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << pre[n] << endl;
    }
}