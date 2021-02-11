#include<bits/stdc++.h>
using namespace std;
long double pi = 3.141592653589793;
int main(){
    int r1, r2, s1, s2, t, d;
    cin >> r1 >> r2; // radii
    cin >> s1 >> s2;    // speeds of m1 and m2
    cin >> t;   // time
    cin >> d;   // dist
    // check if points coincide
    if(r1 + r2 == d){
        if(s1 == s2){
        /// hahahah
            long double e_f = (2 * pi * r1 * 1L) / (s1 * 1L);
            cout << (int)e_f << " " << "E&F";
        }else{
            cout << "no crash";
        }
        return 0;
    }
    // 1st at E
    long double e1 = (2 * pi * r1 * 1L)/ (s1 * 1L);
    long double e2 = (2 * pi * r2 * 1L)/ (s2 * 1L);
    long double limit = 60.000000000;
    vector<long double> v1, v2;
    int n = 4;
    while(limit > e1){
        v1.push_back(e1);
        e1 = (n * pi * r1 * 1L)/ (s1 * 1L), n += 2;
    }
    n = 4;
    while(limit > e2){
        v2.push_back(e2);
        e2 = (n * pi * r2 * 1L)/ (s2 * 1L), n += 2;
    }
    for(auto i : v1)
        cout << i << " ";
    cout << endl;
    for(auto i : v2)
        cout << i << " ";
        cout << endl;
    int ans1 = 0; // E
    // compare
    for(int i = 0; i<v1.size(); i++){
        for(int j = i; j < v2.size(); j++)
            if((int)v1[i] == (int)v2[j]) {ans1 = v1[i]; break;}
    }
    if(ans1){
        cout << ans1 << " " << "E";
        return 0;
    }

    long double f1_diff = v1[2] - v1[1];
    long double f2_diff = v2[1] - v2[0];
    if(f1_diff == v1[])
        f1_diff -= v1[0];
    if(abs(f2_diff - v2[0]) > 0L)
        f2_diff -= v2[0];

}
/*
20
6
8
5
60
23
*/