#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        cout << (long long)(ceil((long double)(ceil((double)n/k)*k)/n)) << endl;
    }    
}