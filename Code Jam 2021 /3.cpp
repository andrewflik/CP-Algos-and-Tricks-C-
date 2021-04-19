#include<bits/stdc++.h>
using namespace std;
vector<int> iter(101), res(101);
void lol(vector<int> &res, vector<int> &iter, int i, int n, int curr){
    // Base Cases
    if(i == n){
        res[i] = curr;
        return;
    }
    if(iter[i] == 1){
        for(int j=i; j<=n; j++) res[j] = curr++;
        return;
    }
    int pos = i + iter[i] - 1;
    res[pos] = curr;
    reverse(res.begin()+i, res.begin()+pos+1);  // excluded 1
    //if(i==2) return;
    lol(res, iter, i+1, n, curr+1);
    reverse(res.begin()+i, res.begin()+pos+1);
}
void lol2(vector<int> &res, vector<int> &iter, int i, int n, int curr){
    for(auto j : iter){
        if(i == n){
            res[i] = curr; break;
        }
        if(j == 1){
            for(int x=i; x<=n; x++) res[x] = curr++;
            break;
        }
        int pos = j + i - 1;
        res[pos] = curr;
        reverse(res.begin()+i, res.begin()+pos+1);
        curr++, i++;
    }
}
void solve(int l, int n, int cost, vector<int> &iter, vector<int> &res){

    int limit = n*(n+1)/2-1;
    if(cost >= n-1 and cost <= limit){
        
        for(int i=0, j=n; i<=n-1; i++)
            iter[i] = j--, res[i] = 0;
        // change it acc to cost
        if(limit != cost){
            for(int i=0, tot=limit-cost; tot!=0 and i<=n-1; i++){
                int k = iter[i] - 1;
                if(tot > k)
                    iter[i] = 1, tot -= k;
                else
                    iter[i] -= tot, tot = 0;
            }
        }
        sort(iter.begin(), iter.end(), greater<int>());
        //vector<int> res(n, 0);
        lol(res, iter, 0, iter.size(), 1);
        cout << "Case #" << l << ": "; 
        for(auto i : res) cout << i << " ";
        cout << endl;
    }else{
        cout << "Case #" << l << ": " << "IMPOSSIBLE" << endl; 
    }
}
int32_t main(){
    int t, l=0;
    cin >> t;
    while(t--){
        int n, cost;
        cin >> n >> cost;
        iter.resize(n-1, 0);
        res.resize(n, 0);
        solve(++l, n, cost, iter, res);
    }
}