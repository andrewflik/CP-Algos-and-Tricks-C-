/*
    Linked List Merge Sort
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
    node(int i):data(i), next(NULL){}
}*root;
void insert(node *head, int data){
    if(!head){
        head->data = data;
        return;
    }
    struct node *temp = head;
    while(temp->next)
        temp = temp->next;
    temp->next = new node(data);
}
void print(node *head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}
node * middle(node *head){
    node * t1 = head, *t2 = head;
    while(t2->next and t2->next->next){
        t1 = t1->next;
        t2 = t2->next->next;
    }
    return t1;
}
int main(){
    root = new node(11);
    insert(root, 22);
    insert(root, 33);
    insert(root, 44);
    insert(root, 55);
    insert(root, 66);
    print(root);
    node *middleRef = middle(root);
    cout << middleRef->data;
}