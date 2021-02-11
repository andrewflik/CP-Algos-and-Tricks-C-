#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, n1, n2;
    cin >> n >> n1 >> n2;
    long long ar[n];
    for(int i=0; i<n; i++)
        cin >> ar[i];
    sort(ar, ar+n, greater<int>());
    long long i = 0, s1 = 0 ,s2 = 0;
    if(n1 > n2) swap(n1, n2);
    for(;i<n1; i++)
        s1 += ar[i];
    for(;i<n2+n1 and i < n; i++)
        s2 += ar[i];
    cout << fixed << setprecision(6) << (long double)s1/n1 + (long double)s2/n2 ;
}