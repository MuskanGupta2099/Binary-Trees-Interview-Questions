#include<iostream> 
#include<unordered_map> 
using namespace std; 

struct Node 
{ 
	int key; 
	struct Node* left, *right, *random; 
}; 

Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->random = temp->right = temp->left = NULL; 
	return (temp); 
} 
void printInorder(Node* node) 
{ 
	if (node == NULL) 
		return; 

	printInorder(node->left); 

	cout << "[" << node->key << " "; 
	if (node->random == NULL) 
		cout << "NULL], "; 
	else
		cout << node->random->key << "], "; 
	printInorder(node->right); 
} 
void mapping(Node* root){
	if(!root){
		return;
	}
	mapping(root -> left);

	Node* newroot = newNode(root -> key);
	Node* rootp1 = root -> left;
	root -> left = newroot;
	newroot -> left = rootp1;

	mapping(root -> right);
}
void setrandom(Node* root){
	if(!root){
		return;
	}
	if(root -> random != NULL){
		root -> left -> random = root -> random -> left;
	}
	else{
		root -> left -> random = NULL;
	}
	setrandom(root -> left -> left);
	setrandom(root -> right);
}
Node* extraction(Node *root){
	if(!root){
		return NULL;
	}
	Node* l = extraction(root -> left -> left);
	Node* r = extraction(root -> right);

	if(!r && !l){
		Node* cloned = root -> left;
		root -> left = NULL;
		return cloned;
	}
	else if(!l && r){
		Node* clone = root -> left;
		clone -> right = r;
		root -> left = NULL;
		return clone;
	}
	else if(!r && l){
		Node* clone = root -> left;
		clone -> left = l;
		root -> left = root -> left -> left;
		return clone;
	}
	else{
		Node* clone = root -> left;
		root -> left = root -> left -> left;
		clone -> left  = l;
		clone -> right = r;
		return clone;
	}
}
Node* cloneTree(Node* tree) 
{ 
	mapping(tree);

	setrandom(tree);

	return extraction(tree);
} 
int main() 
{ 
	Node *tree = newNode(1); 
	tree->left = newNode(2); 
	tree->right = newNode(3); 
	tree->left->left = newNode(4); 
	tree->left->right = newNode(5); 
	tree->random = tree->left->right; 
	tree->left->left->random = tree; 
	tree->left->right->random = tree->right; 

	cout << "Inorder traversal of original binary tree is: \n"; 
	printInorder(tree); 

	Node *clone = cloneTree(tree); 

	cout << "\n\nInorder traversal of cloned binary tree is: \n"; 
	printInorder(clone); 

	return 0; 
} 
