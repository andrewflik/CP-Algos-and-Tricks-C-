#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, c=1, k=0;
        cin >> n;
        while(c <= n)
            c<<=1, k++;
        cout << k << "\n";
    }
}