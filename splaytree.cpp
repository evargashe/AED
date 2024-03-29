#include <bits/stdc++.h> 
using namespace std; 

// An AVL tree node 
class node 
{ 
	public: 
	int key; 
	node *left, *right; 
}; 


node* newNode(int key) 
{ 
	node* Node = new node(); 
	Node->key = key; 
	Node->left = Node->right = NULL; 
	return (Node); 
} 
void insert(node *root, int k)  
{ 
    if(root==nullptr)
        root=newNode(k);
    else if(root->key>k)
        insert(root->left,k);
    else if(root->key<k)
        insert(root->right,k);
    else
    {
        ;
    }  
}
 
node *rightRotate(node *x) 
{ 
	node *y = x->left; 
	x->left = y->right; 
	y->right = x; 
	return y; 
} 

 
node *leftRotate(node *x) 
{ 
	node *y = x->right; 
	x->right = y->left; 
	y->left = x; 
	return y; 
} 

node *splay(node *root, int key) 
{ 
	if (root == NULL || root->key == key) 
		return root;  
	if (root->key > key) 
	{ 
		if (root->left == NULL) return root; 
		if (root->left->key > key) 
		{ 
			root->left->left = splay(root->left->left, key);  
			root = rightRotate(root); 
		} 
		else if (root->left->key < key) // Zig-Zag (Left Right) 
		{ 
			root->left->right = splay(root->left->right, key);  
			if (root->left->right != NULL) 
				root->left = leftRotate(root->left); 
		} 
		return (root->left == NULL)? root: rightRotate(root); 
	} 
	else // Key lies in right subtree 
	{
		if (root->right == NULL) return root; 
		if (root->right->key > key) 
		{ 
			root->right->left = splay(root->right->left, key);  
			if (root->right->left != NULL) 
				root->right = rightRotate(root->right); 
		} 
		else if (root->right->key < key)// Zag-Zag (Right Right) 
		{ 
			root->right->right = splay(root->right->right, key); 
			root = leftRotate(root); 
		} 
		return (root->right == NULL)? root: leftRotate(root); 
	} 
} 

node *search(node *root, int key) 
{ 
	return splay(root, key); 
}

void verArbol(node*&arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->left, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->key <<endl;

     verArbol(arbol->right, n+1);
}

/* Driver code*/
int main()  
{  
    node *root = newNode(100);  
    root->left = newNode(50);  
    root->right = newNode(200);  
    root->left->left = newNode(40);  
    root->left->left->left = newNode(30);  
    root->left->left->left->left = newNode(20);  
    root = search(root, 25);  
    cout<<"Preorder traversal of the modified Splay tree is \n";  
    verArbol(root,0);
    return 0;  
}

// This code is contributed by rathbhupendra 
