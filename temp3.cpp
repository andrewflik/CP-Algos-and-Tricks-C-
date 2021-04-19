// Q3 - Mid point ll
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int d):data(d){next=nullptr;}
}*root;
void print(node *root){
    while(root)
        cout << root->data << " ", root=root->next;
}
int getMid(node *root){
    if(!root) return -1;
    node *f1, *f2;
    f1 = f2 = root;
    while(f2 && f2->next){
        f1 = f1->next;
        f2 = f2->next->next;
    }
    return f1->data;
}
int main(){
    root = new node(12);
    root->next = new node(15);
    root->next->next = new node(13);
    root->next->next->next = new node(10);
    root->next->next->next->next = new node(5);
    root->next->next->next->next->next = new node(8);
    root->next->next->next->next->next->next = new node(11);
    // now the fn that does it
    print(root);
    cout << endl;
    cout << getMid(root);
}