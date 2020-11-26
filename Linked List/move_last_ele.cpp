// Move last element of ll to front
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
    node(int i):data(i), next(nullptr){}
}*root;
void print(node *head){
    while(head){
        cout << head->data << " ";
        head = head->next;  
    }
}
void moveLast(node **head){
    if(!(*head)->next)
        return;
    node *prev, *curr, *hprev, *hcurr, *temp;
    curr = *head;
    temp = curr->next;
    hcurr = curr;
    prev = nullptr;
    while(curr->next)
        prev = curr, curr = curr->next;
    // Swap head with last
    *head = curr;
    curr->next = temp;
    prev->next = hcurr;
    hcurr->next = nullptr;
}
int main(){
    root = new node(5);
    root->next = new node(10);
    root->next->next = new node(15);
    root->next->next->next = new node(20);
    root->next->next->next->next = nullptr;
    print(root);
    cout << endl;
    moveLast(&root);
    print(root);
}