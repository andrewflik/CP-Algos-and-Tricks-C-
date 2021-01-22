/*
    Author - Devesh
    Problem - Max XOR
    This problem can be easliy solved using tries MSB to LSB
*/
#include<bits/stdc++.h>
using namespace std;
struct t{
    t *ar[2];
    t(){ar[0] = ar[1] = nullptr;}
    int insert(unsigned int n){
        unsigned int sum = 0, mask = 2147483648, r, res;
        t *curr = this;
        if(!curr) return 0;
        // Insertion
        for(int i=0; i<=31; i++, mask >>= 1){
            r = mask&n;
            if(r) {
                if(!curr->ar[1]) curr->ar[1] = new t(), curr = curr->ar[1];
                else curr = curr->ar[1];
            }
            else  {
                if(!curr->ar[0]) curr->ar[0] = new t(), curr = curr->ar[0];
                else curr = curr->ar[0];
            }
        }
        curr = this;
        mask = 2147483648;
        // Now look for max of XOR
        res = mask;
        for(int i=0; i<=31; i++, mask >>= 1, res >>= 1){
            r = mask&n;
            if(r){
                if(curr->ar[0]) sum += res, curr = curr->ar[0];
                else
                    curr = curr->ar[1];
            }else{
                if(curr->ar[1]) sum += res, curr = curr->ar[1];
                else curr = curr->ar[0];
            }
        }
        return sum;
    }
    void dfs(t *curr){
        for(int i=0; i<2; i++)
            if(curr->ar[i]){
                cout << i << " ", dfs(curr->ar[i]);
        }
    }
};

void findMaximumXOR(vector<int> &ar){
    t *root = new t();
    int maxn = 0;
    for(int i : ar)
        maxn = max(maxn, root->insert(i));
    //root->dfs(root);
    cout << maxn << endl;
}
int main(){
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int i=0; i<n; i++)
        cin >> ar[i];
    findMaximumXOR(ar);
}
