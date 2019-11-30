// HackerEarth Proble
// Monk watching the fight (BST)
#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left, *right;
	node(){
		left = right = nullptr;
	}
	node(int d){
		left = right = nullptr;
		data = d;
	}
};
void insert(struct node* r, int d){
	// Create a node to be inserted
	struct node* root = r;
	struct node* temp = new node(d);

	// if BST empty
	if(!root){
		root = temp;
		return;
	}
	while(1){
		if(root->data > d){
			if(root->right){
				root = root->right;
			}
			else{
				root->right = temp;
				break;
			}
		}
		else{
			if(root->left){
				root = root->left;
			}
			else{
				root->left = temp;
				break;
			}
		}
	}
}
void preOrder(struct node* root){
	if(root){
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
int heighT(struct node* root){
	if(!root)
		return 0;
	return 1 + max(heighT(root->left), heighT(root->right));
}
int main(){
	int n, a;
	cin >> n;
	cin >> a;
	struct node* root = new node(a); --n;
	while(n--){
		int k;
		cin >> k;
		insert(root, k);
	}
	cout << heighT(root) << endl;
	return 0;
}