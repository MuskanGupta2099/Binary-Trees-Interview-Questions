#include<iostream> 
using namespace std; 

struct Node 
{ 
	struct Node *left, *right; 
	int data; 
}; 
Node* concat(Node* l, Node* r){
	if(!l){
		return r;
	}
	if(!r){
		return l;
	}

	Node* lend = l -> left;
	Node* rend = r -> left;

	lend -> right = r;
	r -> left = lend;

	l -> left = rend;
	rend -> right = l;

	return l;
}
Node *bTreeToCList(Node *root) 
{ 
	if(!root){
		return NULL;
	}
	Node* l = bTreeToCList(root -> left);
	Node* r = bTreeToCList(root -> right);

	root -> right = root;
	root -> left = root;

	Node* temp = concat(l, root);

	return concat(temp, r);
} 
void displayCList(Node *head) 
{ 
	cout << "Circular Linked List is :\n"; 
	Node *itr = head; 
	do
	{	cout << itr->data <<" "; 
		itr = itr->right; 
	} 
	while (head!=itr); 
	cout << "\n"; 
} 
Node *newNode(int data) 
{ 
	Node *temp = new Node(); 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

int main() 
{ 
	Node *root = newNode(10); 
	root->left = newNode(12); 
	root->right = newNode(15); 
	root->left->left = newNode(25); 
	root->left->right = newNode(30); 
	root->right->left = newNode(36); 

	Node *head = bTreeToCList(root); 
	displayCList(head); 

	return 0; 
} 
