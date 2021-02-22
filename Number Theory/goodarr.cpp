#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> divs;
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            divs.push_back(n/i);
            if(n/i!=i)
                divs.push_back(i);
        }
    }
    cout << divs.size() << endl;
    for(auto i : divs)
        cout << i << " ";
}