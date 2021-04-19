#include<bits/stdc++.h>
using namespace std;
bool isSorted(int ar[], int n){
    for(int i=1; i<n; i++){
        if(ar[i-1] > ar[i]) return false;
    }
    return true;
}
void solve(int l){
    int n, cost = 0;
    cin >> n;
    int ar[n];
    for(int i=0; i<n; i++)
        cin >> ar[i];
    // brute force approach for given test cases
    for(int i=0; i<n-1; i++){
        int k=i, curr = ar[i]; 
        for(int j=i; j<n; j++){
            if(curr > ar[j])
                curr = ar[j], k=j;
        }
        cost += (k-i+1);
        cout << cost << " ";
        reverse(ar+i, ar+k+1);
    }
    cout << endl;
    cout << "Case #" << l << ": " << cost << endl; 
}
int main(){
    int t, l=0;
    cin >> t;
    while(t--){
        solve(++l);
    }
}