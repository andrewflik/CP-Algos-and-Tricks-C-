// Q1 - Reverse linked list from a given node
// Ex : 12 15 13 10 5 8 - f(13) -> 12 15 8 5 10 13
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int d):data(d){next=nullptr;}
}*root, *head;
void print(node *root){
    while(root)
        cout << root->data << " ", root=root->next;
}
void rev(int doIt, int n, node **root, node *curr, node *prev, node **link, node **last){
    if(curr){
        if(*link==nullptr && curr->next && curr->next->data == n)
            *link = curr;
        if(!doIt && n == curr->data)
            doIt = 1;
        if(doIt){
            *root = curr;
            struct node *temp;
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            *last = *root;
            rev(doIt, n, root, temp, prev, link, last);
        }else{
            rev(doIt, n, root, curr->next, prev, link, last);
        }
    }
}
int main(){
    root = new node(12);
    root->next = new node(15);
    root->next->next = new node(13);
    root->next->next->next = new node(10);
    root->next->next->next->next = new node(5);
    root->next->next->next->next->next = new node(8);
    head = root;
    // now the fn that does it
    print(head);
    cout << endl;
    node *link, *last;
    link = last = nullptr;
    rev(0, 13, &root, root, nullptr, &link, &last);
    if(link)
        link->next = root, print(head);
    else
        print(head);
}