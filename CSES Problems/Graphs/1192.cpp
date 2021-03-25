#include<bits/stdc++.h>
using namespace std;
int ra[] = {-1, 0, 1, 0};  // top, left, bottom, right
int ca[] = {0, -1, 0, 1};
bool check(int x, int y, int r, int c){
    return ((x >= 0 and x < r) and (y >= 0 and y < c));
}
void dfs(vector<vector<int>> &ar, int i, int j, int r, int c){
    if(check(i, j, r, c)){
        if(!ar[i][j]) return;
        ar[i][j] = 0;
        dfs(ar, i-1, j, r, c);
        dfs(ar, i, j-1, r, c);
        dfs(ar, i+1, j, r, c);
        dfs(ar, i, j+1, r, c);
    }
}
int solve(vector<vector<int>> &ar, int r, int c){
    int ans = 0;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(ar[i][j])
                dfs(ar, i, j, r, c), ans++;
    return ans;
}
int main(){
    char x;
    int r, c;
    cin >> r >> c;
    vector<vector<int>> ar(r, vector<int>(c));
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin >> x, ar[i][j] = (x == '#' ? 0 : 1);
    cout << solve(ar, r, c) << "\n";
}