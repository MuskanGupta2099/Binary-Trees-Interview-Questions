#include <iostream> 
#include <vector> 
#include <bits/stdc++.h>
using namespace std; 

struct Node 
{ 
	int key; 
	struct Node *left, *right; 
}; 

Node * newNode(int k) 
{ 
	Node *temp = new Node; 
	temp->key = k; 
	temp->left = temp->right = NULL; 
	return temp; 
} 
unordered_map<int, int> parents;
unordered_map<int, int> levels;
unordered_map<int, int> grandparents;
int height;
int param;
void calcheight(Node* root){
    height = 0;
    queue<Node*> pending;
    pending.push(root);
    while(!pending.empty()){
        int count = pending.size();
        height++;
        while(count--){
            Node* front = pending.front();
            pending.pop();
            if(front -> left){
                pending.push(front -> left);
            }
            if(front -> right){
                pending.push(front -> right);
            }
        }
    }
    param = ceil(sqrt(height));
}
void fillparents(Node* root, int p){
    if(root == NULL){
        return;
    }
    parents[root -> key] = p;
    fillparents(root -> left, root -> key);
    fillparents(root -> right, root -> key);
}
void filllevels(Node* root, int lev){
    if(!root){
        return;
    }
    levels[root -> key] = lev;
    filllevels(root -> left, lev + 1);
    filllevels(root -> right, lev + 1);
}
void fillgrandparent(Node* root, int grand){
    
    queue<Node*> pending;
    pending.push(root);
    grandparents[root -> key] = -1;
    
    while(!pending.empty()){
        int count = pending.size();
        while(count--){
            Node *front = pending.front();
            pending.pop();
            
            if(front -> left){
                if(levels[front -> left -> key]%param != 0){
                    grandparents[front -> left -> key] = grandparents[front -> key];
                }
                else{
                    grandparents[front -> left -> key] = front -> key;
                }
                pending.push(front -> left);
            }
            if(front -> right){
                if(levels[front -> right -> key]%param != 0){
                    grandparents[front -> right -> key] = grandparents[front -> key];
                }
                else{
                    grandparents[front -> right -> key] = front -> key;
                }
                pending.push(front -> right);
            }
        }
    }
}
int findLCA(Node *root, int n1, int n2) 
{ 
    
    //preprocessing
    fillparents(root, -1);
	filllevels(root, 0);
	calcheight(root);
	fillgrandparent(root, -1);
	
	//if simple ans
    if(parents[n1] == n2){
	    return n2;
	}
	if(parents[n2] == n1){
	    return n1;
	}
	
	//query handling
	
	//shifting the boxes at same boxlevel
	int box1 = levels[n1] / param;
	int box2 = levels[n2] / param;
	
	int heigherbox = max(box1, box2);
	int ntoshiftbox;
	int diffbox = abs(box1 - box2);
	if(heigherbox == box1){
	    ntoshiftbox = n1;
	}else{
	    ntoshiftbox = n2;
	}
	int countbox = 0;
	while(countbox != diffbox){
	    grandparents[ntoshiftbox] = grandparents[grandparents[ntoshiftbox]];
	    countbox++;
	}
	//shifting level to same level
	int lev1 = levels[n1];
	int lev2 = levels[n2];
	int higherlev = max(lev1, lev2);
	int ntoshift;
	int diff = abs(lev1 - lev2);
	if(higherlev == lev1){
	    ntoshift = n1;
	}
	else{
	    ntoshift = n2;
	}
	int count = 0;
	while(count != diff){
	    parents[ntoshift] = parents[parents[ntoshift]];
	    count++;
	}
	//shifting till grandparents equal
	while(grandparents[n1] != grandparents[n2]){
	    grandparents[n1] = grandparents[grandparents[n1]];
	    grandparents[n2] = grandparents[grandparents[n2]];
	}
	//shifting as per parents
	while(parents[n1] != parents[n2]){
	    parents[n1] = parents[parents[n1]];
	    parents[n2] = parents[parents[n2]];
	}
	return parents[n1];
} 

int main() 
{ 
	Node * root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(6); 
	root->right->left = newNode(7); 
	root->right->right = newNode(9); 
	root->left->left -> left = newNode(5); 
	root->left->left -> left -> right = newNode(12);
	root->left->left -> left -> right -> right = newNode(13);
	root->left->left -> left -> right -> right -> right = newNode(15);
	root->left->left -> left -> right -> right -> right -> right = newNode(16);
	root->right->left -> left = newNode(8); 
	root->right->right -> right = newNode(10);
	root->right->right -> right -> left = newNode(11);
	root->right->right -> right -> left -> left = newNode(14);
	root->right->right -> right -> left -> right = newNode(18);
	root->right->right -> right -> left -> left -> right = newNode(17);
	
	cout << "LCA(4, 5) = " << findLCA(root, 17, 18) << endl; 
	cout << "nLCA(4, 6) = " << findLCA(root, 13, 5) << endl; 
	cout << "nLCA(3, 4) = " << findLCA(root, 10, 18) << endl; 
	cout << "nLCA(2, 4) = " << findLCA(root, 6, 11)<< endl;
	return 0; 
}
