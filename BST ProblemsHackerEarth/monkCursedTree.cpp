// HackerEarth Proble
// Monk watching the fight (BST)
#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

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
int heighT(struct node* root){
	if(!root)
		return 0;
	return 1 + max(heighT(root->left), heighT(root->right));
}
struct node* lca(struct node* root, int n1, int n2){
	//if(root->data > n1 && root->data <n2)
	//	return root->data;
	// 1st Case
	if(root->data > n1 && root->data > n2)
		return lca(root->left, n1, n2);
	// 2nd Case
	if(root->data < n1 && root->data < n2)	
		return lca(root->right, n1, n2);

	return root;
}
int maxVal(struct node* root, int x, int y){
	int m = max(x, y);
	struct node* l = lca(root, x, y);
	int val = INT_MIN;

	if(l->data == m)
		return m;
	while(1){
		if(l->data > m){
			if(l->left)
				l = l->left;
		}
		else{
			if(l->right)
				l = l->right;
		}
		if(l->data){
			val = max(val, l->data);
		}
		if(l->data == m)
			break;
	}
	return val;
}
int main(){
	/*struct node* root = new node(4);
	insert(root, 1);
	insert(root, 5);
	insert(root, 0);
	insert(root, 2);
	insert(root, 8);
	preOrder(root);
	cout << endl;
	cout << lca(root, 1, 5) << endl;*/
	//IO
	int n, a;
	cin >> n;
	cin >> a;
	struct node* root = new node(a); --n;
	while(n--){
		int k;
		cin >> k;
		insert(root, k);
	}
	int x, y;	cin >> x >> y;
	cout << maxVal(root, x, y) << "\n";
	return 0;
}