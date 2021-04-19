#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    set<int> s;
    for(int i=0, x; i<n; i++)
        cin >> x, s.insert(x);
    cout << s.size();
}