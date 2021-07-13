#include<bits/stdc++.h>
using namespace std;
// Naive Matching T.C
// n*k*k
struct trie{
    int end;
    trie *node[26];
    trie(){
        for(int i=0; i<26; i++) node[i] = nullptr;
        end = 0;
    }
};
void insert(string &s, trie *link, int curr){
    for(auto i : s){
        if(!link->node[i-'a'])
            link->node[i-'a'] = new trie();
        link = link->node[i-'a'];
    }
    link->end = curr;
}
void search(string &s, trie *link, int n){
    trie *temp;
    vector<bool> ans(n, false);
    for(int i=0; i<s.length(); i++){
        if(link->node[s[i]-'a']){
            temp = link;
            for(int j=i; j<s.length() && temp; j++){
                if(temp->end) ans[temp->end-1] = true;
                temp = temp->node[s[j]-'a']; 
            }
        }
    }
    for(auto i : ans) cout << (bool)i << " "; cout << endl;
}
void dfs(trie *link){
    for(int i=0; i<100; i++){
        if(link->node[i]){
            dfs(link->node[i]);
            delete link->node[i];
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        getchar(); // flush '\n'
        int n;
        string s, inp;
        getline(cin, s); s += " ";
        trie *root = new trie();
        cin >> n; getchar();
        for(int i=0; i<n; i++) cin >> inp, insert(inp, root, i+1);
        // Now search the main string
        search(s, root, n);
        //dfs(root);
        delete root;
    }
}