// Binary String Reduction
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int steps = 0;
        string bin;
        vector<char> temp;
        cin >> bin;
        for(int i=0; i<bin.length(); i++){
            if(bin[i] == '3')
                continue;
            for(int j=0; j<bin.length(); j++){
                if(temp.empty() and bin[j] != '3'){
                    temp.push_back(bin[j]);
                    bin[j] = '3';
                }
                else if(bin[j] != '3' and temp.back() != bin[j]){
                    temp.push_back(bin[j]);
                    bin[j] = '3';
                }
            }
            temp.clear();
            steps++;
        }
        cout << steps << endl;
    }
}