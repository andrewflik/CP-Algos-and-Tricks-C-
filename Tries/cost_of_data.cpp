/*
    Author - Devesh
    Problem - Cost of Data (HackerEarth)
*/
#include<bits/stdc++.h>
using namespace std;
int t = 0;
struct trie{
    trie* ch[26];
    trie(){
        for(int i=0; i<26; i++)
            ch[i] = nullptr;
    }
    void insert(string s){
        trie *curr = this;
        if(!curr) return;
        for(int i=0; i<s.length(); i++){
            if(!curr->ch[s[i] - 'a'])
                curr->ch[s[i] - 'a'] = new trie();
            curr = curr->ch[s[i] - 'a'];
        }
    }
    void dfs(trie *c){
    for(int i=0; i<26; i++)
        if(c->ch[i])
            t++, dfs(c->ch[i]);
    }
}*root;
int main(){
    root = new trie();
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        root->insert(s);
    }
    root->dfs(root);
    cout << ::t + 1;
}