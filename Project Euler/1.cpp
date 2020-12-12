/*  
    PROJECT EULER SOLUTIONS

    Author - Devesh
    Problem - Multiples of 3 & 5
    Topic - Exclusion and Inclusion Principle
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long n, s3, s5, s15;
        cin >> n; n-=1;
        s3 = ((n/3) * (2*3 + ((n/3) - 1)*3))/2;
        s5 = ((n/5) * (2*5 + ((n/5) - 1)*5))/2;
        s15 = ((n/15) * (2*15 + ((n/15) - 1)*15))/2;
        cout << s3 + s5 - s15 << endl;
    }
}
