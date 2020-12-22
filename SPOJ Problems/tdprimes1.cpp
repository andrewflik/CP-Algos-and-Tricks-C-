/*
    Author - Devesh
    Problem - TDPRIMES (SPOJ)
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4, limit = 1e8;
vector<int> primes;
vector<bool> p(limit, true);
int main(){
    //ofstream f("outptut.txt", ios::out);
    primes.push_back(2);
    p[0] = p[1] = false;
    for(int j=4; j<limit; j+=2)
        p[j] = false;
    for(int i=3, c=1; i<limit; i+=2){
        if(p[i]){
            c++;
            if(c%100 == 1) primes.push_back(i);
            for(int j=i+i; j<limit; j+=i)
                p[j] = false;
        }
    }
    for(auto i : primes)
        cout << i << "\n";
}