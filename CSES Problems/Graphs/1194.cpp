#include<bits/stdc++.h>
using namespace std;
char ar[1001][1001]; 
int dist[1001][1001], path[1001][1001], vis[1001][1001];
pair<int, int> parent[1001][1001];
queue<pair<int, int>> q;
int main(){
    int n, m, srcX, srcY;
    cin >> n >> m;
    char c;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin >> c;
            ar[i][j] = c;
            dist[i][j] = INT_MAX;
            if(c == 'A') dist[i][j] = 0, srcX = i, srcY = j, parent[i][j] = {-1, -1};
            if(c == 'M') q.push(make_pair(i, j));
  
        }
    auto check = [&](int x, int y){
        if(x>=0&&x<n&&y>=0&&y<m&&ar[x][y]=='.')return true; 
        return false;
    };
    auto bound = [&](int x, int y){
        if(ar[x][y]=='.'&&(x==0||x==n-1||y==0||y==m-1))return true;
        return false;
    };
    auto move = [](pair<int, int> &d, pair<int, int> &s){
        // d to s
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        char dc[] = {'D', 'R', 'U', 'L'};
        for(int i=0; i<4; i++)
            if(make_pair(d.first+dx[i], d.second+dy[i])==s)
                return dc[i];
        return dc[0];
    };
    auto getPath = [&](pair<int, int> &dest){
        auto last = dest;
        string ans = "";
        for(auto i=parent[dest.first][dest.second]; i!=make_pair(-1, -1); i=parent[i.first][i.second]){
            ans+=move(last, i);
            last = i;
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    };
    // 1st step - min dist of each cell from the nearest 'M' = 2 i.e bfs for all 'M'
    while(!q.empty()){
        pair<int, int> curr = q.front(); q.pop();
        // visit all neighbours of curr
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for(int i=0; i<4; i++)
            if(check(curr.first+dx[i], curr.second+dy[i]) and dist[curr.first+dx[i]][curr.second+dy[i]] == INT_MAX)
                q.push({curr.first+dx[i], curr.second+dy[i]}), dist[curr.first+dx[i]][curr.second+dy[i]] = dist[curr.first][curr.second]%INT_MAX + 1;
    }

    // cout << endl;
    // 2nd step - DFS/BFS on A and find the path with smaller dist then 'M'
    q.push({srcX, srcY});
    while(!q.empty()){
        pair<int, int> curr = q.front(); q.pop();
        vis[curr.first][curr.second] = 1;
        if(bound(curr.first, curr.second)){
            // on bound
            cout << "YES\n" << path[curr.first][curr.second] << "\n";
            getPath(curr);
            return 0;
        }
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for(int i=0; i<4; i++)
            if(!vis[curr.first+dx[i]][curr.second+dy[i]]&&check(curr.first+dx[i], curr.second+dy[i]) && dist[curr.first+dx[i]][curr.second+dy[i]] > path[curr.first][curr.second] + 1)
                q.push({curr.first+dx[i], curr.second+dy[i]}), path[curr.first+dx[i]][curr.second+dy[i]] = path[curr.first][curr.second] + 1, parent[curr.first+dx[i]][curr.second+dy[i]] = {curr.first, curr.second};
    }
    cout << "NO\n";
}