#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
vector<int> g[100001], visited(100001);
struct node{
    int data = 0;
    struct node *l, *r;
    node(int d=0):data(d), l(nullptr), r(nullptr){}
};
void dfsT(node *root){
    if(root){
        cout << root->data << " ";
        dfsT(root->l);
        dfsT(root->r);
    }
}
string bfsG(int i){
    string res = "";
    res += to_string(i) + "n";
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int curr = q.front(), here = 0;
        visited[curr] = true;
        q.pop();
        for(auto i : g[curr]){
            if(!visited[i]){
                q.push(i);
                //cout << i << " ";
                res += to_string(i) + "c";
                here = true;
            }
        }
        if(here)
            res += "n";
    }
    return res;
}
void t2g(node *root){
    int tnodes = 1;
    // a little bfs never hurt nobody
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node *curr = q.front();
        q.pop();
        if(curr->l){
            g[curr->data].push_back(curr->l->data);
            g[curr->l->data].push_back(curr->data);
            q.push(curr->l);
            tnodes++;
        }
        if(curr->r){
            g[curr->data].push_back(curr->r->data);
            g[curr->r->data].push_back(curr->data);
            q.push(curr->r);
            tnodes++;
        }
    }
}
int main(){
    int r, tn;
    cin >> r;
    if(r == -1){
        return 0;
    }
    node *target, *root = new node(r);
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node *curr = q.front();
        q.pop();
        int left, right;
        cin >> left;
        if(left!=-1){
            node *ln = new node(left);
            curr->l = ln;
            q.push(ln);
        }
        cin >> right;
        if(right!=-1){
            node *lr = new node(right);
            curr->r = lr;
            q.push(lr);
        }
    }
    cin >> tn;
    t2g(root);
    //dfsT(root);
    string res  = bfsG(tn);
    //cout << res;
    // strip res
    string fin = "";
    //fin += res[0];
    for(int i=0; i<res.length()-1; i++){
        if(res[i] == 'c' and res[i+1] == 'n'){
            continue;
        }else if(res[i] == 'n'){
            fin += '\n';
        }else if(res[i] == 'c'){
            fin += ' ';
        }else{
            fin += res[i];
        }
    }
    cout << fin;
}