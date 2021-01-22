/*
    Author - Devesh
    Problem - Max XOR of 2 Nums
*/
#include<bits/stdc++.h>
using namespace std;
int findMaximumXOR(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    set<int> s;
    int r = 1, mask = 0;
    for(int i=30; i>=0 ;i--){
        mask = 1 << i;
        for(int j : nums){
            s.insert(j&mask);
        }
        if(s.size() > 1){
            break;
        }else{
            s.clear();
        }
    }
    cout << mask << endl;
    for(int x : s)
        cout << x << " ";
    int a = -1, b = -1;
    for(int j : nums){
        if(a > 0 and b > 0) break;
        if(j&mask == 0) a = j;
        if(j&mask > 1) b = j;
    }
    cout << a << " " << b << endl;
    return a^b;
}
int main(){
   vector<int> a({10, 8, 2});
    cout << findMaximumXOR(a);
}