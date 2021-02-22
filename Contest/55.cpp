/*
    Author - Devesh
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long n, m, k, c = 0;
        cin >> n >> m >> k;
        if(n&1) c++;
        if(m&1) c++;
        long a = 0, b = 0, r = __gcd(n, m);
        if(r!= 1){
            a = (n*m)/r;
        }else{
            long t1 = (n*m)/m;
            long t2 = (n*m)/m;
            long t3 = t1 + t2 - 1;
            a = t3;
        }
        cout << a + c << "\n";
    }
}