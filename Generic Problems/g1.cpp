/*
    Very good question based on greedy
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n;
        vector<int> nodes(n), a(n), b(n);
        for(int i=0; i<n; i++)
            cin >> nodes[i];
        for(int i=0; i<n; i++)
            cin >> a[i];
        for(int i=0; i<n; i++)
            cin >> b[i];

        long long ans = 0, lans = 0, cl = 0;
        for(int i=1; i<n; i++){
            cl = abs(a[i] - b[i]) + nodes[i] + 1ll;
            // max of wether itd contribute or not
            if(a[i] != b[i])
                cl = max(cl, + nodes[i] + 1ll + lans - abs(a[i] - b[i]));
            ans = max(cl, ans);
            lans = cl;
        }
        cout << ans << endl;
    }
}