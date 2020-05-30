#include <iostream>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int data;
	Node *left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = this->right = nullptr;
	}
};

// Function to find diameter of the binary tree. Note that the function
// returns the height of the subtree rooted at given node and diameter
// is updated within the function as it is passed by reference
pair<int, int> helper(Node * root){
    if(!root){
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> l = helper(root -> left);
    pair<int, int> r = helper(root -> right);
    
    int lh = l.first;
    int ld = l.second;
    int rh = r.first;
    int rd = r.second;
    
    int ht = max(lh, rh) + 1;
    int dia = max(lh + rh + 1, max(ld, rd));
    
    pair<int, int> ans;
    ans.first = ht;
    ans.second = dia;
    return ans;
}
int getDiameter(Node* root)
{
	pair<int, int> ans = helper(root);
	
	return ans.second;
}

int main()
{
	Node* root = nullptr;

	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

	cout << "The diameter of the tree is " << getDiameter(root);

	return 0;
}