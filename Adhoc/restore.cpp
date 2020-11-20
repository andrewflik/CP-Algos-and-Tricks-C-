// Restore Sequence
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7;
vector<bool> fact(maxn, true);
vector<int> primes;
void sieve(){
    for(int i=2; i<maxn; i+=2)
        fact[i] = false;
    fact[2] = true, fact[1] = false;
    primes.push_back(2);
    for(int i=3; i<maxn; i+=2){
        if(fact[i]){
            primes.push_back(i);
            for(int j=i+i; j<maxn; j+=i)
                fact[j] = false;
        }
    }
}
int main(){
    sieve();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int B[n], A[n];
        for(int i=0; i<n; i++)
            cin >> B[i];
        for(int i=0; i<n; i++){
            A[i] = primes[B[i]];
        }
        // Print
        for(int i=0; i<n; i++)
            cout << A[i] << " ";
        cout << "\n";
    }
}