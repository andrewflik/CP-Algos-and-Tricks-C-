#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ar[n];
        for(int i=0; i<n; i++)
            cin >> ar[i];
        // check for ai <= pi
        bool possible = false;
        for(int i=0; i<n; i++){
            if(i+1 < ar[i])
                possible = true;
        }
        if(possible){
            cout << "Second\n";
            continue;
        }
        int s = 0;
        for(int i=0; i<n; i++){
            s += ((i+1) - ar[i]);
        }
        if(s&1) cout << "First\n";
        else    cout << "Second\n";
    }
}
