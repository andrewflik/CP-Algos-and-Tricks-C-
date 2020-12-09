/*
    Author - Devesh
    Problem - Minimum Window Substring
    Topic - Sliding Window
*/
#include<bits/stdc++.h>
using namespace std;
bool avail(unordered_map<char, int> &ht, unordered_map<char, int> &st){
    if(st.empty())
        return false;
    for(auto i : ht){
        if(st.find(i.first) == st.end())
            return false;
    }
    return true;
}
string minWindow(string s, string t){
    if(s == t)
        return s;
    int l = 0, r = 0, minLen = INT_MAX, len = 0;
    int left = 0, right = 0;
    unordered_map<char, int> ht, st;
    for(char i : t)
        ht[i]++;
    while(r < s.length()){
        st[t[r]]++;
        if(!avail(ht, st)){
            cout << "ds";
            r++;
            cout << l << " " << r << endl;
        }
        else{
            cout << l << " " << r << " q";
            len = r-l+1, 
            l++;
            if(len < minLen)
                minLen = len, left = l, right = r;
            st[l-1] -= 1;
            if(st[l-1] == 0)
                st.erase(st[l-1]);
        }
    }
    cout << left << " " << right << endl;
    return s.substr(left, right+1);
}
int main(){
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t) << endl;
}