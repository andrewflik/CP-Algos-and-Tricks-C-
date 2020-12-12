/*  
    PROJECT EULER SOLUTIONS

    Author - Devesh
    Problem - Largest prime factor
    Hint -  Sieve
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> primes;
vector<bool> p(1000005, true);
void sieve(){
    for(int i=4; i<1000005; i+=2)
        p[i] = false;
    p[0] = p[1] = false;
    primes.push_back(2);
    for(int i=3; i<1000005; i+=2){
        if(p[i]){
            primes.push_back(i);
            for(int j=i+i; j<1000005; j+=i)
                p[j] = false;
        }
    }
}
long findLargestPrime(long n){
    if(n < 1000005 and p[(int)n])
        return n;
    if(n == 1)
        return 0;
    if(n == 2 or n == 3)
        return 1;
    long maxn = INT_MIN;
    for(auto i : primes){
        if(n == 1)
            break;
        while(n%i == 0){    
            n /= i;
            if(maxn < i)
                maxn = i;
        }
    }
    if(n!=1)
        return n;
    return maxn;
}
int main(){
    sieve();
    int t;
    cin >> t;
    while(t--){
        long n;
        cin >> n;
        cout << findLargestPrime(n) << endl;
    }
}
