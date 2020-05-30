
#include <bits/stdc++.h> 
using namespace std; 

struct node 
{ 
	int data; 
	struct node *left, *right; 
}; 
struct node* newNode (int data) 
{ 
	struct node* temp = 
(struct node* ) malloc(sizeof(struct node)); 

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
struct node *constructTree (int post[], 
							int size) 
{ 
	int start = size - 1;
	stack<item> st;
	struct node* root = newNode(post[start]);
	start --;
	item newitem;
	newitem.n = root;
	newitem.minn = INT_MIN;
	newitem.maxx = root -> data - 1;
	newitem.isleft = true;
	st.push(newitem);
	item newitem2;
	newitem2.n = root;
	newitem2.minn = root -> data + 1;
	newitem2.maxx = INT_MAX;
	newitem2.isleft = false;
	st.push(newitem2);

	while(start >= 0 && !st.empty()){
		item topitem = st.top();
		st.pop();
		if(topitem.isleft == false && (post[start] <= topitem.maxx && post[start] >= topitem.minn)){

			struct node* r = newNode(post[start]);
			start --;
			topitem.n -> right = r;
			item nitem;
			nitem.n = r;
			nitem.minn = topitem.minn;
			nitem.maxx = r -> data - 1;
			nitem.isleft = true;
			st.push(nitem);
			item nitem2;
			nitem2.n = r;
			nitem2.minn = r -> data + 1;
			nitem2.maxx = topitem.maxx;
			nitem2.isleft = false;
			st.push(nitem2);
		}
		else if(topitem.isleft == true && (post[start] <= topitem.maxx && post[start] >= topitem.minn)){


			struct node* l = newNode(post[start]);
			start --;
			topitem.n -> left = l;
			item nitem;
			nitem.n = l;
			nitem.minn = topitem.minn;
			nitem.maxx = l -> data - 1;
			nitem.isleft = true;
			st.push(nitem);
			item nitem2;
			nitem2.n = l;
			nitem2.minn = l -> data + 1;
			nitem2.maxx = topitem.maxx;
			nitem2.isleft = false;
			st.push(nitem2);
		}
		else{
			continue;
		}
	}
	return root;
} 

void printInorder (struct node* node) 
{ 
	if (node == NULL) 
		return; 
	printInorder(node->left); 
	cout << node->data << " "; 
	printInorder(node->right); 
} 
int main () 
{ 
	int post[] = {1, 7, 5, 50, 40, 10}; 
	int size = sizeof(post) / sizeof(post[0]); 

	struct node *root = constructTree(post, size); 

	cout << "Inorder traversal of "
		<< "the constructed tree: \n"; 
	printInorder(root); 

	return 0; 
} 
