#include <bits/stdc++.h> 
using namespace std; 
class node 
{ 
	public: 
	int data; 
	node* left; 
	node* right; 
}; 

node* helper(node* root){
	if(!root){
		return NULL;
	}
	if(root -> left){

		node* l = helper(root -> left);
		while(l -> right){
			l = l -> right;
		}
		l -> right = root;
		root -> left = l;
	}
	if(root -> right){

		node *r = helper(root -> right);
		while(r -> left){
			r = r -> left;
		}
		r -> left = root;
		root -> right = r;
	}
	return root;
}
node* bintree2list(node *root) 
{ 
	if(!root){
		return NULL;
	} 
	root = helper(root);

	while(root -> left){
		root = root -> left;
	}

	return root;
} 
node* newNode(int data) 
{ 
	node* new_node = new node(); 
	new_node->data = data; 
	new_node->left = new_node->right = NULL; 
	return (new_node); 
} 
void printList(node *node) 
{ 
	while (node != NULL) 
	{ 
		cout << node->data << " "; 
		node = node->right; 
	} 
} 
int main() 
{ 

	node *root = newNode(10); 
	root->left = newNode(12); 
	root->right = newNode(15); 
	root->left->left = newNode(25); 
	root->left->right = newNode(30); 
	root->right->left = newNode(36); 


	node *head = bintree2list(root); 

 
	printList(head); 

	return 0; 
} 

