#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
int c[maxn];
int main(){
    int n;
    cin >> n;
    for(int i=0, x; i<n; i++){
        cin >> x;
        for(int i=1; i*i<=x; i++){
            if(x%i==0){
                c[x/i]++;
                if(x/i!=i)
                    c[i]++;
            }
        }
    }
    for(int i=maxn-1; i>=1; i--)
        if(c[i] > 1){cout << i; return 0;}
}