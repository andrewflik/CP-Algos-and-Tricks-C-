/*
    Author - Devesh
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long qn = 0, x, y, z, ta = INT_MAX, td = INT_MIN;
        long long n;
        cin >> n;
        for(long long i=0; i<n; i++){
            cin >> x >> y >> z;
            qn += z;
            //ta = min(ta, x);
            td = max(td, y);
        }
        cout << (long long)ceil((long double)qn / (td - 1 + 1)) << "\n"; 
    }
}