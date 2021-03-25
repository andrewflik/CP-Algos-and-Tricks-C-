#include<bits/stdc++.h>
using namespace std;
bool cmpX(pair<int, int> &p1, pair<int, int> &p2){
    return p1.first < p2.first;
}
bool cmpY(pair<int, int> &p1, pair<int, int> &p2){
    return p1.second < p2.second;
}
int main(){
    int n, maxd = 0;
    cin >> n;
    pair<int, int> points[n];
    for(int i=0; i<n; i++) 
        cin >> points[i].first >> points[i].second;
    sort(points, points+n, cmpX);   // sort according to X values
    long long maxX = points[n-1].first - points[0].first;
    sort(points, points+n, cmpY);
    long long maxY = points[n-1].second - points[0].second;
    long long ans = 1ll * max(maxX, maxY);
    //cout << maxX << " " << maxY << endl;
    cout << ans * ans  << endl;
}