/*
    Author - Devesh
    Problem - Consecutive 1's in Binary Numbers
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, maxc = 0;
    cin >> n;
    int mask = 1;
    for(int i=0, ones = 0; i<32; i++){
        if(n&mask)
            ones++;
        else
            ones = 0;
        mask <<= 1;
        maxc = max(maxc, ones);
    }
    cout << maxc;
}