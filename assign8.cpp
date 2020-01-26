//============================================================================
// Name        : assing8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class node
{
	node* left;
	node* right;
	string key;
	string meaning;
	public:
	node(string k,string m)
	{
		left=NULL;
		right=NULL;
		key=k;
		meaning=m;
	}
	friend class avl;
};
class avl
{
	node* root;
	public:
	avl()
	{
		root=NULL;
	}
	void create();
	int height(node* );
	int balfact(node* );
	node* LL(node*);
	node* LR(node*);
	node* RL(node*);
	node* RR(node*);
	node* insert(node* p,string k);
	void inorder(node*);
	void descend(node*);
	node* getroot()
	{
		return root;
	}
	node* Delete(node* ,string);
	void update(node* ,string);
};

void avl::inorder(node* p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		cout<<p->key<<"-"<<p->meaning<<"\t"<<"bal fact-"<<balfact(p)<<"\t"<<"Height-"<<height(p)<<endl;
		inorder(p->right);
	}
}
void avl::descend(node* p)
{
	if(p!=NULL)
	{
		descend(p->right);
		cout<<p->key<<"-"<<p->meaning<<"\t"<<"bal fact-"<<balfact(p)<<"\t"<<"Height-"<<height(p)<<endl;
		descend(p->left);
	}
}
int avl::balfact(node* p)
{
	int lh=0,rh=0;
	lh=height(p->left)+1;
	rh=height(p->right)+1;

	return lh-rh;

}
int avl::height(node* p)
{
	if(p==NULL)
	{
		return -1;
	}
	else
	{
		int l=height(p->left);
		int r=height(p->right);

		if(l<r)
		return r+1;

		else
		return l+1;
	}
}
node* avl::LL(node* t)
{
	node* p=t->left;
	t->left=p->right;
	p->right=t;
	return p;

}
node* avl::LR(node* t)
{
	node* p=t->left;
	node* q=p->right;
	p->right=q->left;
	q->left=p;
	t->left=q;

	t=LL(t);
	return t;

}
node* avl::RR(node* t)
{
	node* p=t->right;
	t->right=p->left;
	p->left=t;
	return p;

}
node* avl::RL(node* t)
{
	node* p=t->right;
	node* q=p->left;
	p->left=q->right;
	q->right=p;
	t->right=q;
	t=RR(t);
	return t;

}
void avl::create()
{
	char ch;
	string k;
	do
	{
		cout<<"Enter the word"<<endl;
		cin>>k;
		root=insert(root,k);
		cout<<"Add more(y/n)?"<<endl;
		cin>>ch;
	}while(ch=='y' || ch=='Y');
}
node* avl::insert(node* p,string k)
{
	if(p==NULL)
	{
		string m;
		cout<<"Enter the meaning  of"<<k<<endl;
		cin>>m;
		return new node(k,m);
	}
	else
	{

		if(k<p->key)
		{
			p->left=insert(p->left,k);
			if(balfact(p)==2)
			{
				if(k<p->left->key)
				{
					p=LL(p);
				}
				else
				{
					p=LR(p);
				}
			}
			return p;
		}
		if(k>p->key)
		{
			p->right=insert(p->right,k);

			if(balfact(p)==-2)
			{
				if(k>p->right->key)
				{
					p=RR(p);
				}
				else
				{
					p=RL(p);
				}
			}
			return p;
		}
		else if(k==p->key)
		{
			cout<<"Keyword present already"<<endl;
		}
		return p;
	}

}
node* avl::Delete(node* p,string k)
{
	node* t;
	if(p==NULL)
	{
		cout<<"Keyword not found in dictionary"<<endl;
		return NULL;
	}
	else if(k<p->key) //keyword less than
	{
		p->left=Delete(p->left,k);
		if(balfact(p)==-2)
		{
			if(balfact(p->right)<=0)
			{
				p=RR(p);
			}
			else
			{
				p=RL(p);
			}
		}
	//	return p;

	}
	else if(k>p->key) //keyword greater than
	{
		p->right=Delete(p->right,k);
		if(balfact(p)==2)
		{
			if(balfact(p->left)>=0)
			{
				p=LL(p);
			}
			else
			{
				p=LR(p);
			}
		}
//return p;
	}
	else
	{
		if(p->right!=NULL)
		{
			t=p->right;
			while(t->left!=NULL)
				t=t->left;
			p->key=t->key;
			p->right=Delete(p->right,t->key);
			if(balfact(p)==2)
				if(balfact(p->left)>=0)
					p=LL(p);
				else
					p=LR(p);
		}
		else
			return(p->left);
	}


	return p;


}
void avl::update(node* t,string k)
{
	if(t==NULL)
	{
		cout<<"Keyword not found,can't update"<<endl;
		return;
	}
	if(k<t->key)
	{
		update(t->left,k);
	}
	else if(k>t->key)
	{
		update(t->right,k);
	}
	else if(k==t->key)
	{
		string m;
		cout<<"Enter new meaning of "<<t->key<<"\t"<<endl;
		cin>>m;
		t->meaning=m;
		cout<<"Updated successfully"<<endl;
	}

}
int main()
{
	string k,m;
	avl obj;
	int x;
	while(1)
	{
		cout<<"MENU"<<endl<<"1.Create avl tree"<<endl<<"2.Insert into bst"<<endl;
		cout<<"3.Delete the given keyword"<<endl;
		cout<<"4.Update the given meaning"<<endl<<"5.Max comparisons"<<endl;
		cout<<"6.Print in ascending order(inorder)"<<endl<<"7.Print in descending order"<<endl;
		cout<<"8.exit"<<endl;
		cin>>x;
		switch(x)
		{
			case 1:
					obj.create();

			 	 	 break;
			case 2:
					cout<<"Enter the keyword  inserted"<<endl;
					cin>>k;

					obj.insert(obj.getroot(),k);


					 break;
			case 3:
					cout<<"Enter keyword to be deleted"<<endl;
					cin>>k;
					obj.Delete(obj.getroot(),k);

					 break;
			case 4:
					cout<<"Enter keyword whose meaning is to be updated"<<endl;
					cin>>k;
					obj.update(obj.getroot(),k);
					 break;
			case 5:
					cout<<"Enter keyword for which max comparison is to be found"<<endl;
					cin>>k;
					cout<<"Maximum number of comparisons"<<obj.height(obj.getroot());
					 break;
			case 6:
					cout<<"Ascending order of the tree"<<endl;
					obj.inorder(obj.getroot());
					 break;
			case 7:
					cout<<"Descending order of the tree"<<endl;
					obj.descend(obj.getroot());
					break;


			case 8:
					exit(0);

			default:
				cout<<"Invalid choice,enter again"<<endl;
				continue;

		}




	}
}
