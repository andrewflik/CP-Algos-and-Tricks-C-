/*
    Author - Devesh
    Problem - Prime1
    Topic - Idea is to use Segemented Sieve
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 35001;
vector<int> primes;
vector<bool> p(maxn, true);
void sieve(){
    p[0] = p[1] = false;
    for(int i=4; i<maxn; i+=2)
        p[i] = false;
    primes.push_back(2);
    for(int i=3; i<maxn; i+=2){
        if(p[i]){
            primes.push_back(i);
            for(int j=i+i; j<maxn; j+=i)
                p[j] = false;
        }
    }
}
int main(){
    sieve();
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        vector<bool> segment(r-l+1, true);
        for(int i : primes)
            for(int j = max(i+i, (l+i-1)/i*i); j<=r; j+=i)
                segment[j-l] = false;
        if(l == 1) segment[0] = false;
        for(int i=l, j=0; j<=r-l; i++, j++)
            if(segment[j])
                cout << i << "\n";
        cout << "\n";
    }
}