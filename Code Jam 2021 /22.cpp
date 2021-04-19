#include<bits/stdc++.h>
using namespace std;
int getCost(string s, int n, int x, int y){
       int cost = 0;

        for(int i=0; i<=n-1; i++){
            if(s[i] == 'C' and s[i+1] == 'J')
                cost += x;
            if(s[i] == 'J' and s[i+1] == 'C')
                cost += y;
        }
        return cost;
}
int solve(int i, int n, int x, int y, string s){
    string t = s;
    for(int i=0; i<=n-1; i++){
        if(s[i] == '?')
            s[i] = 'C';
    }
    for(int i=0; i<=n-1; i++){
        if(t[i] == '?')
            t[i] = 'J';
    }
    int ans = min(getCost(s, n, x, y), getCost(t, n, x, y));
    return ans;
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