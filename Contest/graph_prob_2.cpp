/*
    Author - Devesh
    Problem - Roads and Libraries (HackerRank)
    Topic - DSU & Connected Components
*/
#include<bits/stdc++.h>
using namespace std;
int tc = 0;
void dfs(int curr, vector<int> &v, vector<int> g[]){
    if(v[curr]) return;
    v[curr] = 1, tc++;
    for(auto i : g[curr])
        dfs(i, v, g);
}
int32_t main(){
    int n, p;
    cin >> n >> p;
    vector<int> g[n+1];
    vector<int> v(n+1, false);
    for(int i=0, x, y; i<p; i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int totalCountries = 0;
    vector<int> countries;
    for(int i=0; i<n; i++){
        if(!v[i])
            dfs(i, v, g), countries.push_back(tc), totalCountries++;
        tc = 0;
    }
    long long res = 0;
    // O(N^2) approach - Naive Approach
    // Lets optimize this combinations using a simple fact that
    // a*b + a*c + a*d is equal to a(b+c+d)
    /*for(int i=0; i<totalCountries; i++){
        for(int j=i+1; j<totalCountries; j++){
            res += (1LL * countries[i] * countries[j]);
        }
    }*/
    long long sum = 0;
    for(auto i : countries)
        sum += i;
    for(int i=0; i<totalCountries; i++){
        sum -= countries[i];
        res += countries[i] * sum;
    }
    cout << res << endl;
}