#include<bits/stdc++.h>
using namespace std;
int getR(vector<vector<int>> &v){
    
}
int getC(vector<vector<int>> &v){
    
}
int main(){
    int r, c;
    cin >> r >> c;
    vector<vector<int>> v(r, vector<int>(c, 0));
    cout << min(getR(v), getC(v));    
}