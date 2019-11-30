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
}*root=nullptr;
void insert(struct node* r, int d){
	// Create a node to be inserted
	struct node* root = r;
	struct node* temp = new node(d);
	// If BST empty
	if(root->data == -1){
		root->data = d;
		return;
	}
	while(1){
		if(root->data > d){
			if(root->left){
				root = root->left;
			}
			else{
				root->left = temp;
				break;
			}
		}
		else{
			if(root->right){
				root = root->right;
			}
			else{
				root->right = temp;
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
void buildBST(struct node* r, int ar[], int s, int e){
	if(s <= e){
		int m = (s+e)/2;
		insert(r, ar[m]);
		buildBST(r, ar, s, m-1);
		buildBST(r, ar, m+1, e);
	}
}
int main(){
	int ar[] = {1, 2, 3, 4, 5, 6, 7};
	root = new node(-1);
	buildBST(root, ar, 0, 6);
	/*insert(root, 4);
	insert(root, 2);
	insert(root, 1);
	insert(root, 3);
	insert(root, 6);
	insert(root, 7);
	insert(root, 5);*/
	preOrder(root);
	return 0;
}
