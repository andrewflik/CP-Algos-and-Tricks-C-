/*
    Author - Devesh
    TRIES IMPLEMENTATION
*/
#include<bits/stdc++.h>
using namespace std;
struct tries{
    bool v;
    tries *ch[26];
    tries(){  
        for(int i=0; i<26; i++) ch[i] = nullptr;
        v = false;
    }
    void insert(string str){
        tries *curr = this;
        for(char i : str){
            if(!curr->ch[i-'a'])    // if it doesnt exist
                curr->ch[i-'a'] = new tries();
            curr = curr->ch[i-'a']; // move along 
        }
        curr->v = true;
    }
    bool search(string key){
        tries *curr = this;
        if(!curr) return false;
        for(int i=0; i<key.length(); i++){
            curr = curr->ch[key[i] -'a'];
            if(!curr) return false;
        }
        return true;
    }
};
void dfs(tries *curr){
    for(int i=0; i<26; i++){
        if(curr->ch[i]){
            cout << char(i + 'a') << " " << curr->v << endl;
            dfs(curr->ch[i]);
        }
    }
}
int main(){
    tries *head = new tries();
    head->insert("c");
    head->insert("i");
    head->insert("f");
    dfs(head);
    cout << endl;
    cout << head->search("helo");
}