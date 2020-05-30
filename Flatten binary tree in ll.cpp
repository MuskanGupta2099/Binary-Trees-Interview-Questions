#include <iostream> 
using namespace std; 

class Node { 
public:
	int key; 
	Node *left, *right; 
}; 

Node* newNode(int key) 
{ 
	Node* node = new Node; 
	node->key = key; 
	node->left = node->right = NULL; 
	return (node); 
} 

void flatten(Node* root) 
{ 
	if(!root){
		return;
	}
	if(!root -> left && !root -> right){
		return;
	}
	if(root -> left){
		flatten(root -> left);
		Node* temp = root -> right;
		root -> right = root -> left;
		root -> left = NULL;

		Node* tempright = root -> right;\
		while(tempright -> right != NULL){
			tempright = tempright -> right;
		}
		tempright -> right = temp;
	}

	flatten(root -> right);
} 

void inorder(Node* root) 
{ 
	// base condition 
	if (root == NULL) 
		return; 
	inorder(root->left); 
	cout << root->key << " "; 
	inorder(root->right); 
} 

int main() 
{ 
	/* 1 
		/ \ 
	2	 5 
	/ \	 \ 
	3 4	 6 */
	Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(5); 
	root->left->left = newNode(3); 
	root->left->right = newNode(4); 
	root->right->right = newNode(6); 

	flatten(root); 

	cout << "The Inorder traversal after "
			"flattening binary tree "; 
	inorder(root); 
	return 0; 
} 
