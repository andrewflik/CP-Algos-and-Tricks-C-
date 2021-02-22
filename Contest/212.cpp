/*
    Author - Devesh
*/
#include<bits/stdc++.h>
using namespace std;

int ar[200005], c[200005];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x=0;
        cin >> n;
        for(int i=1 ;i<=n; i++) cin >> ar[i], c[ar[i]] = i;
        for(int i=1; i<=n; i++)
            if(i!=ar[i]){
                x=1,swap(ar[i], ar[c[i]]); break;
            }
        if(!x)
            swap(ar[n], ar[n-1]);
        for(int i=1; i<=n; i++)
            cout << ar[i] << " ";
        cout << endl;
    }
}