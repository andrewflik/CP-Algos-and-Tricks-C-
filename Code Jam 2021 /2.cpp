#include<bits/stdc++.h>
using namespace std;
int solve(int i, int n, int x, int y, string s){
    if(i == n){
        int cost = 0;
        // calculate cost
        for(int i=0; i<=n-1; i++){
            if(s[i] == 'C' and s[i+1] == 'J')
                cost += x;
            if(s[i] == 'J' and s[i+1] == 'C')
                cost += y;
        }
        return cost;
    }
    string t = s;
    if(s[i] == '?'){
        s[i] = 'J';
        t[i] = 'C';
    }
    return min(solve(i+1, n, x, y, s), solve(i+1, n, x, y, t));
}
void solve(int l){
    int x, y;
    string s;
    cin >> x >> y >> s;
    int cost = solve(0, s.length()-1, x, y, s);
    cout << "Case #" << l << ": " << cost << endl; 
}
int main(){
    int t, l=0;
    cin >> t;
    while(t--){
        solve(++l);
    }
}