/*
    Author - Devesh
    Problem - Divisible Pairs Sum
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k, t = 0;
    cin >> n >> k;
    int ar[n];
    for(int i=0; i<n; i++)
        cin >> ar[i];
    /* O(n) */
    unordered_map<int, int> h;
    for(auto i : ar)
        h[i%k]++;   // Store a[i] % k
        
    for(auto i : h){
        if(i.first == 0)
            t += (i.second * (i.second - 1))/2;
        else if(k-i.first == i.first)
            t += (i.second * (i.second - 1))/2;
        else
            t += i.second * (h[k-i.first]), i.second = 0, h[k-i.first] = 0;

        //cout << t << endl;
    }
    /* Alternate approach with array
        /* O(n) 
    int h[n] = {0};
    for(auto i : ar)
        h[i%k]++;   // Store a[i] % k
    
    t += (h[0] * (h[0] - 1))/2;
    for(int i=1; i<n; i++){
        if(k-i == i)
            t += (h[i] * (h[i] - 1))/2;
        else
            t += h[i] * (h[k-i]), h[i] = 0, h[k-i] = 0;

        //cout << t << endl;
    }
    cout << t << endl;
    */
    cout << t << endl;
    /* O(n*n) approach
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((ar[i] + ar[j]) % k == 0)
                t++;
        }
    }4
    */ 
} 

 