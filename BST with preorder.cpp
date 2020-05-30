#include <bits/stdc++.h> 
using namespace std; 

class node 
{ 
	public: 
	int data; 
	node *left; 
	node *right; 
}; 

node* newNode (int data) 
{ 
	node* temp = new node(); 

	temp->data = data; 
	temp->left = temp->right = NULL; 

	return temp; 
} 

 class item{
public:
	struct node* n;
	int minn;
	int maxx;
	bool isleft;
};
node *constructTree (int pre[], int size) 
{ 
	int start = 0;
	stack<item> st;
	node* root = newNode(pre[start]);
	start ++;
	item newitem2;
	newitem2.n = root;
	newitem2.minn = root -> data + 1;
	newitem2.maxx = INT_MAX;
	newitem2.isleft = false;
	st.push(newitem2);
	item newitem;
	newitem.n = root;
	newitem.minn = INT_MIN;
	newitem.maxx = root -> data - 1;
	newitem.isleft = true;
	st.push(newitem);
	

	while(start < size && !st.empty()){
		item topitem = st.top();
		st.pop();
		if(topitem.isleft == false && (pre[start] <= topitem.maxx && pre[start] >= topitem.minn)){

			node* r = newNode(pre[start]);
			start ++;
			topitem.n -> right = r;
			item nitem2;
			nitem2.n = r;
			nitem2.minn = r -> data + 1;
			nitem2.maxx = topitem.maxx;
			nitem2.isleft = false;
			st.push(nitem2);
			item nitem;
			nitem.n = r;
			nitem.minn = topitem.minn;
			nitem.maxx = r -> data - 1;
			nitem.isleft = true;
			st.push(nitem);
			
		}
		else if(topitem.isleft == true && (pre[start] <= topitem.maxx && pre[start] >= topitem.minn)){


			node* l = newNode(pre[start]);
			start ++;
			topitem.n -> left = l;
			item nitem2;
			nitem2.n = l;
			nitem2.minn = l -> data + 1;
			nitem2.maxx = topitem.maxx;
			nitem2.isleft = false;
			st.push(nitem2);
			item nitem;
			nitem.n = l;
			nitem.minn = topitem.minn;
			nitem.maxx = l -> data - 1;
			nitem.isleft = true;
			st.push(nitem);
			
		}
		else{
			continue;
		}
	}
	return root;
}  
void printInorder (node* node) 
{ 
	if (node == NULL) 
		return; 
	printInorder(node->left); 
	cout<<node->data<<" "; 
	printInorder(node->right); 
} 

int main () 
{ 
	int pre[] = {10, 5, 1, 7, 40, 50}; 
	int size = sizeof( pre ) / sizeof( pre[0] ); 

	node *root = constructTree(pre, size); 

	cout<<"Inorder traversal of the constructed tree: \n"; 
	printInorder(root); 

	return 0; 
} 