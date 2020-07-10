"""
    Author - Devehs
    Problem - Army Game (HackerRank)
"""

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, tot, tot4, tot2, tot1, c = 0;
    cin >> n >> m;
    tot = n*m;
    
    tot4 = (n/2)*(m/2);
    c += tot4;  // Every 4 blocks cover 1 supply
    tot -= (tot4*4);
    
    tot2 = tot/2;   
    c += tot2;
    tot -= (tot2*2);    // Every remaining block of 2 gets 1 supply
    
    tot1 = tot;      // Remaming one block to get 1 supply each
    c += tot1;
    tot -= tot1;
    cout << c;
}
