/*
    Author - Devesh
    Problem - Common Divisors (CSES)
*/
#include<iostream>
#include<unordered_map>
using namespace std;
int m[1000001];
//unordered_map<int, int> m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        for (int j = 1; j*j <= a; j++) {
            if(a % j == 0) {
                m[j]++; 
                if (j != a / j) m[a / j]++; 
            }
        }
    }
    for(int i=1000001; i>=1; i--){
        if(m[i] > 1){
            cout << i;
            return 0;
        }
    }
    /*int ans = 0;
    for(auto i : m)
        if(i.second > 1)
          ans = max(ans, i.first);*/
    //cout << ans;
}