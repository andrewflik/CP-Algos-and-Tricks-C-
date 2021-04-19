#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ar[n], dp[n+1];
        for(int i=0; i<n; i++)
            cin >> ar[i], dp[i]=1;
        for(int i=n-2,l; i>=0; i--){
            l=ar[i+1] > 0 ? 1 : 0;
            if(ar[i]>0&&l) dp[i] = 1;
            else if(ar[i]<0&&l==0) dp[i]=1;
            else dp[i] = dp[i+1]+1;
        }
        for(int i=0 ;i<n;i++)cout<<dp[i]<<" ";
        cout << endl;
    }
}