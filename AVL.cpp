//Program for AVL Tree Operations.//
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	int height;
};
class AVLtree
{
	private:
		int height(struct Node*);
		int max(int,int);
		struct Node *newnode(int);
		struct Node *rightrotate(struct Node*);
		struct Node *leftrotate(struct Node*);
		int getbalance(struct Node*);
		public:
			struct Node*insert(struct Node*,int);
			int searchnode(struct Node*,int);
			void preorder(struct Node*);
};
int AVLtree::height(struct Node *N)
{
	if(N==NULL)
	return 0;
	return N->height;
}
int AVLtree::max(int a,int b)
{
	return (a>b)?a:b;
}
struct Node* AVLtree::newnode(int key)
{
	struct Node *node=(struct Node*)malloc(sizeof(struct Node));
	node->data=key;
	node->right=NULL;
	node->left=NULL;
	node->height=1;
	return(node);
}
struct Node* AVLtree::rightrotate(struct Node*gp)
{
	struct Node*par=gp->left;
	struct Node*T3=par->right;
	par->right=gp;//start of rotation
	gp->left=T3;
	gp->height=max(height(gp->left),height(gp->right))+1;
	par->height=max(height(par->left),height(par->right))+1;
	return par;
}
struct Node* AVLtree::leftrotate(struct Node*gp)
{
	struct Node*par=gp->right;
	struct Node*T2=par->left;
	par->left=gp;
	gp->right=T2;
	gp->height=max(height(gp->left),height(gp->right))+1;
	par->height=max(height(par->left),height(par->right))+1;
	return par;
}
int AVLtree::getbalance(struct Node*N)
{
	if(N==NULL)
	return 0;
	return height(N->left)-height(N->right);
}
struct Node* AVLtree::insert(struct Node*node,int key)
{
	if(node==NULL)
	return(newnode(key));
	if(key<=node->data)
	node->left=insert(node->left,key);
	else
	node->right=insert(node->right,key);
	node->height=1+max(height(node->left),height(node->right));
	int balance=getbalance(node);
	if(balance>1&&key<node->left->data)
	return rightrotate(node);
	if(balance<-1&&key>node->right->data)
	return leftrotate(node);
	if(balance>1&&key>node->left->data)
	{
		node->left=leftrotate(node->left);
		return rightrotate(node);
	}
	if(balance<-1&&key<node->right->data)
	{
		node->right=rightrotate(node->right);
		return leftrotate(node);
	}
	return node;
}
int AVLtree::searchnode(struct Node*root,int key)
{
	struct Node*ptr=root;
	if(ptr==NULL)
	return 0;
	if(ptr->data==key)
	return 1;
	else if(key<ptr->data)
	searchnode(ptr->left,key);
	else
	searchnode(ptr->right,key);
}
void AVLtree::preorder(struct Node*root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
int main()
{
	int op,key;
	struct Node*root=NULL;
	AVLtree a;
	do
	{
		cout<<"\n1.insert\n2.search\n3.preorder display";
		cout<<"\n4.exit";
		cout<<"\nchoose an option :";
		cin>>op;
		switch(op)
		{
			case 1:
				cout<<"\nenter value to insert";
				cin>>key;
				root=a.insert(root,key);
				break;
				case 2:
				cout<<"\nenter key to search";
				cin>>key;
				if(a.searchnode(root,key))
				cout<<key<<"key found";
				else
				cout<<key<<"not found";
				break;
				case 3:
				cout<<"\npreorder traversal is";
				a.preorder(root);
				break;
				case 4:
				exit(0);	
		}
	}
	while(op!=5);
	return 0;
}

