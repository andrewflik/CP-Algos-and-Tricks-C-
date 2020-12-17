/*  
    PROJECT EULER SOLUTIONS

    Author - Devesh
    Problem - Largest palindrome product
*/
#include<bits/stdc++.h>
using namespace std;
bool c(string s){
    int l = 0, r = s.length()-1;
    while(l<r){
        if(s[l++]!=s[r--])
            return false;
    }
    return true;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        long num, n, i, j;
        cin >> n;
        for(i=999; i>=100; i--){
            bool flag = false;
            for(j=999; j>=100; j--){
                num = 1L * i * j;
                if(num <= n and c(to_string(num))){
                    cout << num << endl;
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        cout << i << " " << j << endl;
        //cout << num << endl;
    }
}