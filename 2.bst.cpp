//============================================================================
// Name        : bst.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <cstring>
#include<cstdlib>
using namespace std;

class node
{
public:
	string w,m;
	node* lchild;
	node* rchild;

	node(string word,string meaning)
	{
		w=word;
		m=meaning;
		lchild=rchild=NULL;
	}
	friend class tree;
};

class tree
{

public:
  tree()
{root=NULL;}
	node *root;
	node* insert(node* t,string nw,string nm)
	{
		node *p;
		if(root==NULL)
		{
			root=new node(nw,nm);
			return root;

		}
		else
		{
			if(t==NULL)

			{
				p=new node(nw,nm);
				return p;
			}
			else

			{
				if(nw < t->w)
				{

					t->lchild=insert(t->lchild,nw,nm);
				}
				else
				{
					t->rchild=insert(t->rchild,nw,nm);
				}
			}
			return t;
		}
	}
	void display(node *t)
	{
		if(t!=NULL)
		{
			cout<<"\nkeyword:";
			cout<<t->w;
			cout<<"\nmeaning:";
			cout<<t->m;
			display(t->lchild);
			display(t->rchild);
		}
	}
	node* inorder(node* t)
	{
		if(t!=NULL)
		{
			inorder(t->lchild);
			cout<<"\nkeyword:"<<t->w<<"\nmeaning"<<t->m;
			inorder(t->rchild);
		}
	}
	node* decend(node* t)
		{
			if(t!=NULL)
			{
				inorder(t->rchild);
				cout<<"\nkeyword:"<<t->w<<"\nmeaning"<<t->m;
				inorder(t->lchild);
			}
		}
	void operator=(tree &d)
	{
		root=copy(d.root);
	}
	node* copy(node* t)
	{
		if(t==NULL)
			return t;
		node* temp;
		while(t!=NULL)
		{
		temp=new node(t->w,t->m);
		temp->lchild=copy(t->lchild);
		temp->rchild=copy(t->rchild);
	    return temp;
		}
	}
	node* search(node* t,string k)
	{
		while(t!=NULL)
		{
			if(k==t->w)
				return t;
			else
			{
				if(k<t->w)
					t=search(t->lchild,k);
				else
					t=search(t->rchild,k);
			}

			return t;

		}
	}
	void update()
	{
       node *u;
       string nm,uw;
       cout<<"\nenter the word you want to update";
       cin>>uw;
       u=search(root,uw);
       if(u!=NULL)
       {
    	   cout<<"\nenter the new meaning";
    	   cin>>nm;
    	   u->m=nm;
       }
	}

	node* delete_node(node *t,string dw)
	{
		node *p;
		if(t==NULL)
		{
			return 0;

		}
		else if(dw<t->w)
		{
		t->lchild=delete_node(t->lchild,dw);
			return t;
		}
		else if(dw>t->w)
		{
			t->rchild=delete_node(t->rchild,dw);
			return t;

	     }
		else if(t->lchild==NULL && t->rchild==NULL)
		{

			p=t;
			free(p);
			return NULL;
		}
		else if(t->lchild==NULL)
		{
             p=t->lchild;
             while(p->rchild!=NULL)
             {
            	 p=p->rchild;

             }
             t->w=p->w;
             t->m=p->m;
             return delete_node(p,p->w);
		}
		else
		{
			p=t->rchild;
			while(p->lchild!=NULL)
			{
				p=p->lchild;

			}
		t->w=p->w;
		t->m=p->m;
		return(delete_node(p,p->w));
	   }
		return 0;
	}
};
int main()
{
	node *new_n,*n;
	string w,m,s,d;
	tree t ,t1;;
	int ch;
	do
	{
		cout<<"\n1.insert"<<"2.display"<<"3.ascending"<<"4.copy"<<"5.search"<<"6.decending"<<"7.update"<<"8.delete";
		cout<<"\n enter the choice";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"\nenter the word";
			cin>>w;
			cout<<"\nenter the meaning";
			cin>>m;
			new_n=t.insert(new_n,w,m);
			cout<<"node entered";
			break;
		case 2:
			t.display(t.root);
			break;
		case 3:
			t.inorder(t.root);
			break;
		case 4:

			t1=t;
			t1.display(t1.root);
			break;
		case 5:

			cout<<"enter the word to be search";
			cin>>s;
			n=t.search(t.root,s);
			cout<<"\nsearched data is";
			cout<<"\nkeyword:"<<n->w<<"\nmeaning:"<<n->m;
			break;
		case 6:
			t.decend(t.root);
			break;
		case 7:
			t.update();
			cout<<"\n after update ";
			t.display(t.root);
		case 8:
			cout<<"\n enter the word you want to delete";
			cin>>d;
			n=t.delete_node(t.root,d);
			t.display(n);
			break;
		}
	}while(ch<9);
}
