// Merge Sort on LinkedList
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
    node(int i=0):data(i), next(nullptr){}
}*head, *init;
void insert(node **head, int data){
    if(!(*head)){
        *head = new node(data);
        return;
    }
    node* temp = new node(data);
    (*head)->next = temp;
    *head = temp;
}
void print(node *head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}
void middle(node *head, node **a, node **b){
    node *first, *second;
    first = head;
    second = head;
    while(second->next and second->next->next){
        second = second->next->next;
        first = first->next;
    }
    *a = head;
    *b = first->next;
    first->next = nullptr;  // Divide the linked list into two parts litreally
}
node* mergell(node *first, node *second){
    if(!first)
        return second;
    else if(!second)
        return first;

    node *result = NULL;
    if(first->data <= second->data){
        result = first;
        result->next = mergell(first->next, second);
    }else{
        result = second;
        result->next = mergell(first, second->next);
    }
    return result;
}
node* mergell2(node *first, node *second){
    node *result = NULL, *temp = NULL;
    while(first and second){    
        if(first->data <= second->data){
            result = first;
            first = first->next;
        }else{
            result = second;
            second = second->next;
        }
        result = result->next;
        result->next = temp;
    }       
    result->next = nullptr;
    return result;
}
void mergesort(node **head){
    node *a = nullptr, *b = nullptr, *h = nullptr;
    h = *head;
    if(h == nullptr or h->next == nullptr)
        return;
    middle(*head, &a, &b);
    mergesort(&a);
    mergesort(&b);
    //cout << a->data << " " << b->data << endl;
    *head = mergell2(a, b);
}
int main(){
    head = new node(5);
    init = head;
    insert(&head, 10);
    insert(&head, 2);
    insert(&head, 1);
    insert(&head, 6);
    insert(&head, 8);
    print(init);
    mergesort(&init);
    cout << endl;
    print(init);
}