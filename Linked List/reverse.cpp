// Reversing a linked list
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
    node(int i): data(i){}
}*root;

void print(node *head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}
// O(n) and O(1)
void reverse(node **roott){
    node *curr, *prev = nullptr, *next;
    curr = *roott;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr; 
        curr = next;
    }
    *roott = prev;
}
int main(){
    root = new node(12);
    root->next = new node(22);
    root->next->next = new node(33);
    root->next->next->next = new node(44);
    root->next->next->next->next = nullptr;
    print(root);
    reverse(&root);
    cout << endl;
    print(root);
}