//============================================================================
// Name        : assing6h.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

# define max 1000

class node
{
public:
	string key,value;
	node *next;

	node()
	{
		next=NULL;
	}
	node(string key,string value)
	{
		this->key=key;
		this->value=value;
	}
	friend class dictionary;

};

class dictionary
{
public:
	node *head[max];

	dictionary()
	{
	for(int i=0;i<max;i++)
	{
		head[i]=NULL;
	}
	}

	void insert(string word,string meaning)
	{
		int ind=hash(word);
		node *p=new node(word,meaning);

		if(head[ind]==NULL)
		{
			head[ind]=p;
			cout<<word<<"inserted"<<endl;
		}
		else
		{
			node *start=head[ind];
			if(start->next!=NULL)
			{
				start=start->next;
				start=p;
				cout<<word<<"inserted"<<endl;
			}
		}
	}
	void insertr(string word,string meaning)
		{
			int ind=hash(word);
			node *p=new node(word,meaning);
            node *temp=new node();
			if(head[ind]==NULL)
			{
				head[ind]=p;
				cout<<word<<"inserted"<<endl;
			}
			else
			{
				if(head[ind]!=NULL);
				{
				temp=head[ind];


				if(temp->next!=NULL)
				{
					temp=temp->next;
					temp->next=p;
					cout<<word<<"inserted"<<endl;
				}
			}
		}
	}
	int hash(string word)
	{
		int sum=0;

			sum=sum+word[0];

		return(sum%10);
	}
	string find(string word)
	{
	 int index=hash(word);

	 node *start=head[index];
	 if(start==NULL)
	  return "-1";
	 while(start!=NULL)
	 {
	  if(start->key==word)
	   return start->value;
	  start=start->next;
	 }
	 return "-1";
	}
	void display()
	{
		for(int i=0;i<max;i++)
		{
			if(head[i]!=NULL)
			{
			cout<<"bucket no:"<<i;
			cout<<"keyword"<<head[i]->key;
			cout<<"meaning"<<head[i]->value;
			}

		}
	}

	bool deleteword(string word)
	{
	 int index=hash(word);
	 node *tmp=head[index];
	 node *par=head[index];
	 if(tmp==NULL)
	 {
	  return false;
	 }
	 if(tmp->key==word && tmp->next==NULL)
	 {
	  tmp->next=NULL;
	  delete tmp;
	  return true;
	 }

	 while(tmp->key!=word && tmp->next!=NULL)
	 {
	  par=tmp;
	  tmp=tmp->next;
	 }
	 if(tmp->key==word&&tmp->next!=NULL)
	 {
	  par->next=tmp->next;
	  tmp->next=NULL;
	  delete tmp;
	  return true;
	 }
	 else
	 {
	  par->next=NULL;
	  tmp->next=NULL;
	  delete tmp;
	  return true;
	 }
	 return false;
	}
};

int main()
{
	dictionary d;
	string word,meaning,w,m;
	int ch;

	do
	{
	cout<<"1.insert without replacement"<<endl;
	cout<<"2.insert with replacemennt"<<endl;
	cout<<"3.find"<<endl;
	cout<<"4.display"<<endl;
	cout<<"5.delete"<<endl;
	cout<<"enter your choice";
	cin>>ch;

	switch(ch)
	{
	case 1:
		cout<<"enter the word"<<endl;
		cin>>word;
		cout<<"enter the meaning"<<endl;
		cin>>meaning;
		d.insert(word,meaning);
		break;
	case 2:
			cout<<"enter the word"<<endl;
			cin>>word;
			cout<<"enter the meaning"<<endl;
			cin>>meaning;
			d.insertr(word,meaning);
			break;
	case 3:
		cout<<"enter the word"<<endl;
		cin>>w;
		m=d.find(w);
		if(m!="-1")
			cout<<"word is present"<<endl;
		    cout<<"word:"<<w<<"  "<<"meaning:"<<m<<endl;
		 break;
	case 4:
		d.display();
		break;
	case 5:
		cout<<"enter the word to delete";
		cin>>word;
		if(d.deleteword(word))
			cout<<"world is deleted";
		else
			cout<<"word is not deleted";
		break;
	}
	}while(ch<6);
}

