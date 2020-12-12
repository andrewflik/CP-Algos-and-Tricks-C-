/*  
    PROJECT EULER SOLUTIONS

    Author - Devesh
    Problem - Even Fibonacci numbers
    Hint -  Obeserve Pattern of Even Occurences 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long n;
        cin >> n;
        long s = 0, curr = 2, last = 0, e;
        while(n > curr){
            s += curr;
            e = curr * 4 + last;
            last = curr;
            curr = e;
        }
        cout << s << endl;
    }
}
