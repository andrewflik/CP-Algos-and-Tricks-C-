/*
    Author - Devesh
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        long c0, c1, ansl = 0, ansr = 0;
        cin >> n >> c0 >> c1;
        int tl[n], tr[n], ar[n];
        tl[0] = 0, tr[0] = 1;
        for(int i=0, x; i<n; i++)
            cin >> ar[i];
        for(int i=1; i<n; i++)
            if(tl[i-1] == 0) tl[i] = 1;
            else tl[i] = 0;
        for(int i=1; i<n; i++)
            if(tr[i-1] == 1) tr[i] = 0;
            else tr[i] = 1;

        // Left
        for(int i=0; i<n; i++)
            if(ar[i] != tl[i])
                if(ar[i] == 0)
                    ansl += c0;
                else
                    ansl += c1;
        // Right
        for(int i=0; i<n; i++)
            if(ar[i] != tr[i])
                if(ar[i] == 0)
                    ansr += c0;
                else
                    ansr += c1;
        
        if(ansl > ansr)
            cout << ansr << "\n";
        else
            cout << ansl << "\n";
    }
}