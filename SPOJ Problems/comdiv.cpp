/*
    Author - Devesh
    Problem - COMDIV (SPOJ)
*/
#include<bits/stdc++.h>
using namespace std;
/*const int maxn = 1e4;
vector<int> primes;
vector<bool> p(maxn, true);
void sieve(){
    for(int i=4; i<maxn; i+=2)
        p[i] = false;
    p[0] = p[1] = false;
    primes.push_back(2);
    for(int i=3; i<maxn; i+=2){
        if(p[i]){
            primes.push_back(i);
            for(int j=i+i; j<maxn; j+=i)
                p[j] = false;
        }
    }
}
int fact(int f, int d){
    if(f == 1) return 1;
    if(f == 2) return 1 + (d%f == 0 ? 1 : 1);
    int comdiv = 1, tdiv = 1, sf = 0;
    if(f == d)
        sf = 1;
    for(auto i : primes){
        comdiv = 1;
        if(f == 1) break;
        while(f%i==0){
            if(d%i == 0 or sf == 1) d /= i, comdiv++;
            f /= i;
        }
        tdiv *= comdiv;
    }
    return tdiv;
}*/
int fact(int f){
    if(f == 1) return 1;
    if(f == 2) return 2;
    int comdiv = 2;
    for(int i=2; i<=sqrt(f); i++){
        if(f%i == 0){
            if(f/i == i)
                comdiv++;
            else
                comdiv+=2;
        }
    }
    return comdiv;
}
int main(){
    //sieve();
    int t;
    scanf("%d", &t);
    while(t--){
        int n1, n2, r;
        scanf("%d %d", &n1, &n2);
        r = __gcd(n1, n2);
        if(r == 1){
            //cout << 1 << endl;
            printf("%d\n", 1);
            continue;
        }
        printf("%d\n", fact(r));//cout << fact(n2, n1) << endl;
        //else if(n1 < n2)
        //    printf("%d\n", fact(n1, r));//cout << fact(n1, n2) << endl;
        //else
        //    printf("%d\n", fact(r, n2));//cout << fact(n1, n2) << endl;
    }
}