/*
    Problem - Ehab the Xorcist
    Hint - a + b = a^b + 2*(a&b), a + b = a|b + a&b
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long u, v;
    cin >> u >> v;    
    if(u == v){
        if(u)
            cout << 1 << " " << u << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    if(u>v or ((v-u)&1)){
        cout << -1 << endl;
        return 0;
    }

    long long r = (v-u)/2;
    if(((v-r)^(r)) == u)
        cout << 2 << "\n" << r << " " << v-r << endl;
    else
        cout << 3 << "\n" << u << " " << r << " " << r << endl; 
}