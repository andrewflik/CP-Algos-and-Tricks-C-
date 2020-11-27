// Return the intersection of two linked lists
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
    node(int i):data(i), next(nullptr){}
}*root1, *root2;

void print(node *head){
    while(head){
        cout << head->data << " ";
        head = head->next;  
    }
}
void intersect(node *r1, node *r2){
    node *h = new node(0);  // Adding a dummy node
    node *temp = h;
    while(r1 and r2){
        if(r1->data > r2->data){
            r2 = r2->next;
        }else if(r1->data < r2->data){
            r1 = r1->next;
        }
        else{
            h->next = new node(r2->data);
            h = h->next;
            r1 = r1->next;
            r2 = r2->next;
        }
    }
    print(temp);
}
int main(){
    root1 = new node(1);
    root1->next = new node(2);
    root1->next->next = new node(3);
    root1->next->next->next = new node(4);
    root1->next->next->next->next = new node(6);
    root1->next->next->next->next->next = nullptr;

    root2 = new node(2);
    root2->next = new node(4);
    root2->next->next = new node(6);
    root2->next->next->next = new node(8);
    root2->next->next->next->next = nullptr;

    print(root1);
    cout << endl;
    print(root2);
    cout << endl;

    intersect(root1, root2);
}