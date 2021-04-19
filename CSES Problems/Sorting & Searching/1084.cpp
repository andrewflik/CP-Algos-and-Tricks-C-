#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k, x;
    cin >> n >> m >> k;
    //int desired[n], avail[m];
    vector<int> desired, avail;
    for(int i=0; i<n; i++)
        cin >> x, avail.push_back(x);
    for(int i=0; i<m; i++)
        cin >> x, desired.push_back(x);
    
    sort(avail.begin(), avail.end());
    sort(desired.begin(), desired.end());
    int total = 0;
    auto check = [&k](int avail, int desired){
        if(desired+k>=avail && desired-k<=avail) return true;
        return false;
    };
    for(int i=0, j=0; i<n&&j<m;){
        // comparing every avail room with desired room
        // and seeing if it matches 
        if(check(avail[i], desired[j]))
            total++, i++, j++;
        else if(avail[i] > desired[j])
            j++;
        else
            i++;
    }
    cout << total << endl;
}