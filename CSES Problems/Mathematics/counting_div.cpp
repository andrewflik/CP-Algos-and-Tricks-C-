/*
    Author - Devesh
    Problem - Counting Divisors
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int x, c = 0;
        cin >> x;
        // sqrt(n) approach -> t * sqrt(n)
        for(int i=1; i<=sqrt(x); i++){
            if(x%i == 0){
                if(x/i == i)
                    c++;
                else
                    c += 2;
            }
        }
        cout << c << endl;
    }
}