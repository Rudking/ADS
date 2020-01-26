//============================================================================
// Name        : assing1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstdlib>
using namespace std;

class node
{
public:
	int data;
	node* lchild;
	node* rchild;

	node(int x)
	{
		data=x;
		lchild=rchild=NULL;
	}
friend class tree;
};

class tree
{
public:
	node* root;

	tree()
	{
		root=NULL;
	}
	void create()
		{
			root=create_rec();
		}

node* create_rec()
{
	node* p;
    int ch,child;


	cout<<"entre the data to insert";
	cin>>ch;

  if(ch==-1)

	  return NULL;

	p=new node(ch);

	cout<<"enter data in left child \n";
		p->lchild=create_rec();
	cout<<"enter data in right child \n";
		p->rchild=create_rec();

	return p;

}

node* postorder(node* t)
{

	if(t!=NULL)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		cout<<t->data;
	}
}
node* preorder(node* t)
{
	t=root;
	if(t!=NULL)
	{
		cout<<t->data;
		postorder(t->lchild);

		postorder(t->rchild);

	}
}
node* mirror(node *t)
{
	node* temp;
	if(t!=NULL)
	{
		mirror(t->lchild);
	    mirror(t->rchild);
	    temp=t->lchild;
	    t->lchild=t->rchild;
	    t->rchild=temp;
	    cout<<t->data;
	}
}
int height(node* t)
{
	int h1,h2;
	if(t==NULL)
		return  0;
	if(t->lchild==NULL && t->rchild)
		return 0;
	h1=height(t->lchild);
	h2=height(t->rchild);
	if(h1>h2)
		return(h1+1);
	else
		return(h2+1);
}
int getcount(node* t)
{
	if(t==NULL)
		return 0;
	if(t->lchild==NULL && t->rchild==NULL)
			return 1;
	else
		return getcount(t->rchild)+getcount(t->lchild);


}
int it_node(node* t)
{
	int l1,l2;
	if(t==NULL)
			return 0;
		if(t->lchild==NULL && t->rchild==NULL)
				return 0;

		else if(t->lchild!=NULL || t->rchild!=NULL)
		{
			 l1=it_node(t->lchild);
			 l2=it_node(t->rchild);
			 return (l1+l2+1);
		}

		else return 1;



}
tree*  operator=(tree *t)
{
	tree *lt,*rt,*t1,*t2;
	if(t!=NULL)
	{
	this->root=t->root;
	lt->root=t->root->lchild;
	rt->root=t->root->rchild;
	t1=lt;
	t2=rt;
	this->root->lchild=lt->root;
	this->root->rchild=rt->root;
	return this;
	}
	else
		return NULL;


}
void delete_node(node *t)
{
	if(t==NULL)
		return;

	delete_node(t->lchild);
	delete_node(t->rchild);
	cout<<"\ndeleted node is"<<t->data;
	free(t);

}
};
int main()
{
	tree t;
	t.create();
	cout<<"\npostorder:";
	t.postorder(t.root);
	cout<<"\npreorder";
	t.preorder(t.root);
	cout<<"\nmirror";
	t.mirror(t.root);
    cout<<"height"<<	t.height(t.root);
	cout<<"leaf node count"<<t.getcount(t.root);
	cout<<"internal node count"<<t.it_node(t.root);
    tree tc;
    tc=t;
    cout<<"\n copied tree in postorder"<<tc.preorder(tc.root);
    cout<<"\n delete tree";
    t.delete_node(t.root);
}

