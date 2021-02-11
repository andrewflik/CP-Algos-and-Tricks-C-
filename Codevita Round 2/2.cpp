#include<bits/stdc++.h>
using namespace std;
int p[10001], v[10001], fund[10001];
void ms(int n){
    p[n] = n;
}
int sf(int n){
    if(n == p[n]) return n;
    return p[n] = sf(p[n]);
}
void us(int a, int b){
    a = sf(a), b = sf(b);
    if(a!=b) p[b] = a; // rank
}
int ts(int n){
    if(v[n] == 1) return 0;
    v[n] = 1;
    if(n == p[n]) return fund[n]; 
    return fund[n] + ts(p[n]);
}
void init(){
    for(int i=0; i<10001; i++) 
        p[i] = v[i] = fund[i] = 0;
}
/*
5
23 43 123 54 2
3
1 3
2 3
1 2

9
34 54 65 76 88 23 56 76 43
7 
1 3
2 3
1 2
6 8
5 4
5 7
8 9
*/
int fp(int n){
    if(n == p[n]) return n;
    return fp(p[n]);
}
int main(){
    init();
    int n, p;
    cin >> n;
    for(int i=1; i<=n; i++) 
        cin >> fund[i], ms(i);
    cin >> p;
    while(p--){
        int p1, p2;
        cin >> p1 >> p2;
        us(p1, p2);
    }
    int h[n+1] = {0};
    for(int i=1; i<=n; i++){
        h[fp(i)] += fund[i];
    }
    int ans = 0;
    for(int i=1; i<=n; i++) ans = max(ans , h[i]);
    cout << ans ;
}