/*
    Author - Devesh
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, ans = 0;
        cin >> n;
        int ar[n];
        for(int i=0; i<n; i++)
            cin >> ar[i];
        unordered_map<int ,pair<int,int>> hash;
        // init
        for(auto i : ar)
            hash.insert({i, make_pair(-1, -1)});
        for(int i=0; i<n; i++){
            if(hash[ar[i]].first == -1)
                hash[ar[i]].first = i;
            else if(hash[ar[i]].second == -1)
                hash[ar[i]].second = i;
            else
                hash[ar[i]].second = i;
        }
        for(auto i : hash)
            if(i.second.second !=-1 and i.second.first != -1)
                ans += i.second.second - i.second.first;
        cout << ans << "\n";
    }
}