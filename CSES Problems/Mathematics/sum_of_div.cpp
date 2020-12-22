/*
    Author - Devesh
    Problem - Sum of Divisors
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    long n, ans = 0;
    cin >> n;
    for(int i=1; i*i<=n; i++){
        if(n % i == 0){
            if(n/i == i)
                ans += i;
            else
                ans += n/i, ans += i;
        }
    }
    cout << ans;
}