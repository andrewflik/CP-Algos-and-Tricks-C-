#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> ar(1001, vector<char>(1001));
vector<vector<int>> d(1001, vector<int>(1001, 0));
vector<vector<pair<int, int>>> path(1001, vector<pair<int, int>>(1001, {0, 0}));
queue<pair<int, int>> q;
vector<pair<int, int>> pathR(1e6+5);
void bfs(int r, int c, pair<int, int> src, pair<int, int> dest){
    // check
    auto check = [](int x, int y, int r, int c){
        return ((x >= 0 and x < r) and (y >= 0 and y < c) and ((ar[x][y] == '.') or ar[x][y] == 'B'));
    };
    // get cords
    auto cords = [](pair<int, int> &src, pair<int, int> &dest) {
        if(src.first == dest.first){
            // same row
            if(src.second > dest.second)
                return 'L';
            return 'R';
        }else{
            // same col
            if(src.first > dest.first)
                return 'U';
            return 'D';
        }
    };
    q.push(src);
    int possible = 0;
    while(!q.empty()){
        pair<int, int> curr = q.front(); q.pop();
        if(curr == dest) {
            // unwind here
            return;
        }
        if(curr!=src)
            ar[curr.first][curr.second] = '#';
        if(check(curr.first-1, curr.second, r, c))
            q.push({curr.first-1, curr.second}), d[curr.first-1][curr.second] = d[curr.first][curr.second] + 1, path[curr.first-1][curr.second] = {curr};
        if(check(curr.first, curr.second-1, r, c))
            q.push({curr.first, curr.second-1}), d[curr.first][curr.second-1] = d[curr.first][curr.second] + 1, path[curr.first][curr.second-1] = {curr};
        if(check(curr.first+1, curr.second, r, c))
            q.push({curr.first+1, curr.second}), d[curr.first+1][curr.second] = d[curr.first][curr.second] + 1, path[curr.first+1][curr.second] = {curr};
        if(check(curr.first, curr.second+1, r, c))
            q.push({curr.first, curr.second+1}), d[curr.first][curr.second+1] = d[curr.first][curr.second] + 1, path[curr.first][curr.second+1] = {curr};
    }
    cout << "NO" << endl;
    // else{    
    //     // for(auto i : path){
    //     // cout << endl;
    //     //     for(auto j : i)
    //     //         cout << j.first << "-" << j.second << "  ";}
    //     // for(pair<int, int> i=dest; ar[i.first][i.second]!='A'; i=path[i.first][i.second])
    //     //     cout << i.first << " " << i.second << endl;
 
    //     pair<int, int> i=dest;
    //     int t=0;
    //     while(ar[i.first][i.second]!='A'){
    //         pathR[t++]=i;
    //         i=path[i.first][i.second];
    //     }
    //     pathR[t++]=i;
    //     reverse(pathR.begin(), pathR.begin()+t);
    //     cout << "YES\n" << d[dest.first][dest.second] << "\n";
    //     pair<int, int> last = pathR[0];
    //     for(int i=1; i<t; last = pathR[i],i++)
    //         cout << cords(last, pathR[i]);
    //     cout << endl;
    // }
}
int main(){
    //     ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int r, c, ii, jj, xx, yy;
    cin >> r >> c;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            cin >> ar[i][j];
            if(ar[i][j] == 'A')
                ii = i, jj = j;
            if(ar[i][j] == 'B')
                xx = i, yy = j;
        }
    bfs(r, c, {ii, jj}, {xx, yy});
}