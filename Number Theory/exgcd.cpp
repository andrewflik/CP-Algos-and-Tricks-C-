#include<bits/stdc++.h>
using namespace std;
int maxn = 0;
long tn = 1;
int sieve(vector<vector<int>> &ranges){
    long gcdSum = 0, en = 0, lastSum = 0, total = 0;
    for(int i=2; i<=maxn; i++){
        int currN = 0;
        for(int j=i+i, lSum = 1; j<=maxn; j+=i){
            // num and its multiples GCD
            for(int l=0; l<ranges.size(); l++){
                lSum *= ((ranges[l][1]/j) - ceil((float)ranges[l][0]/j)) + 1;      // left and right range
            }
            currN += lSum;
        }
       // cout << currN << endl;
        // currN is the exact number
        int pSum = 1;
        for(int c=0; c<ranges.size(); c++)
            pSum *= ((((ranges[c][1]/i)) - ceil((float)ranges[c][0]/i)) + 1);
        gcdSum += (pSum - currN) * i;
        if(lastSum != gcdSum)
            total++, lastSum = gcdSum;
        cout << pSum << " & " << gcdSum << endl;
    }
    //cout << total << endl;
    return gcdSum + (tn - total);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        vector<vector<int>> ranges(k, vector<int>(2, 0)); 
        for(int i=0; i<k; i++)
            cin >> ranges[i][0] >> ranges[i][1], tn *= (ranges[i][1] - ranges[i][0] + 1), maxn = max(maxn, ranges[i][1]);
        cout << "P : " << sieve(ranges) << endl;
        cout << "Q : " << tn << endl;
    }
}