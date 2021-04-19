#include<bits/stdc++.h>
using namespace std;
int solve(int ar[], int n){
    int pre[n];
    pre[0]=ar[0];
    for(int i=1;i<n;i++)pre[i]+=pre[i-1];
    for(int i=1;i<n;i++){
        for(int j=i;j<n;j++){

        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ar[n];
        cout<<solve(ar, n)<<" ";
    }
}