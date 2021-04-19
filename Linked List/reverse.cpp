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
void swap(node **head, int a, int b){
    if(a == b)
        return;
    node *prev1, *prev2, *curr1, *curr2, *root;
    prev1 = prev2 = nullptr;
    curr1 = curr2 = *head;

    node *h = *head;
    while(h){
        if(h->data == a)
            curr1 = h;          
        if(h->data == b)
            curr2 = h;
        if(h->next and h->next->data == a)
            prev1 = h;
        if(h->next and h->next->data == b)
            prev2 = h;
        
        h = h->next;
    }
    /*
    while(curr1 && curr1->data != a){  
        prev1 = curr1;  
        curr1 = curr1->next;  
    }  
    while(curr2 && curr2->data != b){  
        prev2 = curr2;  
        curr2 = curr2->next;  
    }  */

    if(!prev1)
        *head = curr2;
    else
        prev1->next = curr2;

    if(!prev2)
        *head = curr1;
    else
        prev2->next = curr1;

    node *temp;
    temp = curr2->next;
    curr2->next = curr1->next;
    curr1->next = temp;
}
int main(){
    root = new node(12);
    root->next = new node(22);
    root->next->next = new node(33);
    root->next->next->next = new node(44);
    root->next->next->next->next = new node(55);
    root->next->next->next->next->next = nullptr;
    print(root);
    reverse(&root);
    cout << endl;
    print(root);
    //cout << endl;
    //swap(&root, 12, 55);
    //print(root);
}