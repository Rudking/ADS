/*
//============================================================================
// Name        : assing3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define max 20
class node
{
public:
	int data;
	node *lchild;
	node *rchild;
	bool rbit,lbit;
	node(int x)
	{
		data=x;
		lchild=rchild=NULL;
		rbit=lbit=1;
	}
	friend class tbt;
};
class queue
{
 public:
	node* q[max];
 int f,r;

 queue()
 {

	 f=r=1;
 }
	int empty()
	{
		if(r==max-1)
			return 1;
		else
			return 0;
	}
	void push(node* p)
	{
		if(r==max-1)
			cout<<"queue is full";
		else
		{
		 if(r==-1)
		 {
			 f=r=0;
		 q[r]=p;
		 }
		 else
		 {
			 r=r+1;
		     q[r]=p;
		 }
		}
	}

	node* pop()
	{
		node* temp;
		temp=q[f];
		if(f==r)
			f=r=-1;
		else
			f=f+1;
		return temp;
	}
	friend class tbt;
};
class tbt
{
public:
	node *root;
	queue q1;
	tbt()
	{
		root=NULL;
	}

	void create()
	{
		node *p;
		int ch;
		cout<<"enter the data";
		cin>>ch;
		if(root==NULL)
		{
			p=new node(ch);
		root=p;
		p->lchild=p->rchild=p;
		p->lbit=0;
		p->rbit=1;
		}
		else
	    cout<<"head already created";
		insert(q1,ch);

	}
	node* insert(queue q1,int x)
	{
		node *temp,*t;
		char ans;
		q1.push(root);
		while(!q1.empty())
		{
			temp=q1.pop();
			cout<<"do you want to insert on left of"+temp->data<<"(y/n)";
			cin>>ans;
			if(ans=='y')
			{
				t=new node(x);
				linsert(temp,t);
				q1.push(t);
			}
			if(temp!=root)
			{
				cout<<"do you want to insert on left of"+temp->data<<"(y/n)";
			    cin>>ans;
				if(ans=='y')
				{
		        	t=new node(x);
				    rinsert(temp,t);
					q1.push(t);
				}

			}
		}
	}

	node* insert_node(node *s,node *t)
	{
		t->lchild=s->lchild;
		t->rchild=s;
		t->lbit=s->lbit;
		t->rbit=0;
		s->lchild=t;
		s->lbit=1;

	}
	void linsert(node *S,node *T)
		{
			T->lbit=S->lbit;
			T->lchild=S->lchild;
			T->rchild=S;
			T->rbit=0;
			S->lchild=T;
			S->lbit=1;
		}
		void rinsert(node *S,node *T)
		{
			T->rbit=S->rbit;
			T->rchild=S->rchild;
			T->lchild=S;
			T->lbit=0;
			S->rchild=T;
			S->rbit=1;
		}
	node* preorder()
	{
		node *t;
		t=root->lchild;
		while(1)
		{
			if(t==root)
				return 0;
			cout<<t->data;
			if(t->lbit==1)
			{
				t=t->lchild;
			}
			else if(t->rbit==1)
				t=t->rchild;
			else
				while(t->rbit!=1)
				{
					t=t->rchild;
					t=t->rchild;
				}

		}
	}
};

int main()
{
	tbt t;
	int ch;
	do
	{
	cout<<"1.create"<<"2.preorder";
	cout<<"enter your choice";
	cin>>ch;
	switch(ch)
	{
	 case 1:
		t.create();
		break;
	 case 2:
		 t.preorder();
		 break;
	}

	}while(ch<3);
}
*/ .
//============================================================================
// Name        : demo.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class TBT;
class Node
{
	Node *left,*right;
	int data;
	bool rbit,lbit;
public:
	Node()
{
		left=NULL;
		right=NULL;
		data=0;
		rbit=lbit=0;
}
	Node(int d)
	{
		left=NULL;
		right=NULL;
		rbit=lbit=0;
		data=d;
	}
	friend class TBT;
};
class TBT
{
	Node *root;
public:
	TBT()
{
		root=new Node(9999);
		root->left=root;
		root->rbit=1;
		root->lbit=0;
		root->right=root;
}
	void preorder_traversal()
	{
		Node *c=root->left;
		while(c!=root)
		{
			cout<<" "<<c->data;
			c=preorderS(c);//Call to Preorder Successor
		}
	}
	void inorder_traversal()
	{
		Node *c=root->left;
		while(c->lbit==1)
			c=c->left;
		while(c!=root)
		{
			cout<<" "<<c->data;
			c=inorderS(c);//Call to Inorder Successor
		}
	}
	Node* inorderS(Node *c)
	{
		if(c->rbit==0)
			return c->right;
		else
			c=c->right;
		while(c->lbit==1)
		{
			c=c->left;
		}
		return c;
	}
	Node *preorderS(Node *c)
	{
		if(c->lbit==1)
		{
			return c->left;
		}
		while(c->rbit==0)
		{
			c=c->right;
		}
		return c->right;
	}
	void create()
	{
		int n;
		cout<<"\nEnter number of nodes:";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int info;
			cout<<"\nEnter data: ";
			cin>>info;
			this->insert(info);
		}
	}
	void insert(int data)
	{

		if(root->left==root&&root->right==root)
		{
			Node *p=new Node(data);
			p->left=root->left;
			p->lbit=root->lbit;
			p->rbit=0;
			p->right=root->right;
			root->left=p;
			root->lbit=1;
			cout<<"\nInsertion Started->"<<data;
			return;
		}
		Node *cur=new Node;
		cur=root->left;
		while(1)
		{

			if(cur->data<data)   //insert right
			{
				Node *p=new Node(data);
				if(cur->rbit==0)
				{
					p->right=cur->right;
					p->rbit=cur->rbit;
					p->lbit=0;
					p->left=cur;
					cur->rbit=1;
					cur->right=p;
					cout<<"\nInserted right:"<<data;
					return;
				}
				else
					cur=cur->right;
			}
			if(cur->data>data) //insert left
			{
				Node *p=new Node(data);
				if(cur->lbit==0)
				{
					p->left=cur->left;
					p->lbit=cur->lbit;
					p->rbit=0;
					p->right=cur; //successor
					cur->lbit=1;
					cur->left=p;
					cout<<"\nInserted left:"<<data;
					return;
				}
				else
					cur=cur->left;
			}
		}

	}
	void delTBT(){}
};
int main()
{
	TBT t1;
	int value;
	int choice;
	do
	{
		cout<<"\nThreaded Binary Tree:- \n1.Create Tree\n2.Insert into tree\n3.Pre-order\n4.Inorder\n5.Delete\n6.Exit\nEnter your choice:";
		cin>>choice;
		if(choice>5)
			return 0;
		switch(choice)
		{
		case 1:
			t1.create();
			break;
		case 2:
			cout<<"\nEnter Number:";
			cin>>value;
			t1.insert(value);
			break;
		case 3:
			cout<<"\nPreorder traversal of TBT:\n";
			t1.preorder_traversal();
			break;
		case 4:
			cout<<"\nInoder Traversal of TBT:\n";
			t1.inorder_traversal();
			break;
		case 5:
			cout<<"\n Deletion:";
			t1.delTBT();
			break;
		}

	}while(choice!=0);


	return 0;
}

