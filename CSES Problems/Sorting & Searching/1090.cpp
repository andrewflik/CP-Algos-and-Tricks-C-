#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int ar[n];
    for(int i=0; i<n; i++) cin >> ar[i];
    int i = 0, j = n-1, tot = 0;
    // 4 10
    // 2 3 7 9
    sort(ar, ar+n);
    while(i<=j){
        if(ar[i]+ar[j] == x) tot++, i++, j--;
        else if(ar[j] + ar[i] > x) tot++, j--;
        else tot++, i++, j--; 
    }
    cout << tot;
}