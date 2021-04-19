#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ar[n], p[n];
    for(int i=0;i<n;i++) cin>>ar[i],p[i]=0;
    p[0] = ar[0];
    for(int i=1;i<n;i++)p[i]+=p[i-1];
    int m=0,ma=0;
    for(int i=0;i<n;i++)ma=max(p[i],ma),m=min(p[i],m);
    cout<<ma-m<<endl;
}