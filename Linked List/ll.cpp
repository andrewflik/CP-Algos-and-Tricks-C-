/*
    Linked List
    -> Different Insertions
    -> Finding Mid Node
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
    node(int i):data(i), next(NULL){}
}*root;
// T.C - O(n)
void insert1(node *head, int data){
    if(!head){
        head->data = data;
        return;
    }
    struct node *temp = head;
    while(temp->next)
        temp = temp->next;
    temp->next = new node(data);
}
// T.C - O(1)
void insert2(node **till, int data){
    if(!(*till)){
        *till = new node(data);
        return;
    }
    struct node* t = new node(data);
    (*till)->next = t;
    (*till) = t;
}
// T.C - O(1)
void insertRev(node *head, int data){
    struct node *t = new node(data);
    t->next = head;
    head = t;
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
    struct node* init;
    root = new node(11);
    init = root;
    insertRev(root, 22);
    insertRev(root, 33);
    insertRev(root, 44);
    insertRev(root, 55);
    /*
    insert2(&root, 22);
    insert2(&root, 33);
    insert2(&root, 44);
    insert2(&root, 55);
    */
    /*
    insert1(root, 22);
    insert1(root, 33);
    insert1(root, 44);
    insert1(root, 55);
    insert1(root, 66);
    */
    // Print Linked List
    print(root);
    //print(init);
    // Print Middle
    node *middleRef = middle(root);
    cout << middleRef->data << endl;
    // Merge Sort
    sort(root);
}