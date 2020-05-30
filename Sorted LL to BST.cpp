#include <bits/stdc++.h> 
using namespace std; 

/* Link list node */
class LNode 
{ 
	public: 
	int data; 
	LNode* next; 
}; 

/* A Binary Tree node */
class TNode 
{ 
	public: 
	int data; 
	TNode* left; 
	TNode* right; 
}; 

TNode* newNode(int data); 
int countLNodes(LNode* head){
	if(!head){
		return 0;
	}
	int count = 0;
	LNode*temp = head;
	while(temp){
		temp = temp -> next;
		count++;
	}
	return count;
}
TNode* sortedListToBSTRecur(LNode** head, int n){
	if(n == 0){
		return NULL;
	}
	TNode* left = sortedListToBSTRecur(head, n/2);
	TNode* root = newNode((*head) -> data);
	root -> left = left;
	*head = (*head) -> next;
	root -> right = sortedListToBSTRecur(head, n - n/2 - 1);

	return root;

}
TNode* sortedListToBST(LNode *head) 
{ 
	int n = countLNodes(head); 

	return sortedListToBSTRecur(&head, n); 
} 

/* Function to insert a node 
at the beginging of the linked list */
void push(LNode** head_ref, int new_data) 
{ 
	LNode* new_node = new LNode(); 	
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

/* Function to print nodes in a given linked list */
void printList(LNode *node) 
{ 
	while(node!=NULL) 
	{ 
		cout << node->data << " "; 
		node = node->next; 
	} 
} 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
TNode* newNode(int data) 
{ 
	TNode* node = new TNode(); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return node; 
} 

/* A utility function to 
print preorder traversal of BST */
void preOrder(TNode* node) 
{ 
	if (node == NULL) 
		return; 
	cout<<node->data<<" "; 
	preOrder(node->left); 
	preOrder(node->right); 
} 


int main() 
{ 
	LNode* head = NULL; 


	push(&head, 7); 
	push(&head, 6); 
	push(&head, 5); 
	push(&head, 4); 
	push(&head, 3); 
	push(&head, 2); 
	push(&head, 1); 

	cout<<"Given Linked List "; 
	printList(head); 

	
	TNode *root = sortedListToBST(head); 
	cout<<"\nPreOrder Traversal of constructed BST "; 
	preOrder(root); 

	return 0; 
} 
