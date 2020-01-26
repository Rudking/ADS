//============================================================================
// Name        : assingment4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
#define max 20
class node
{
public:
	node* next;
	int time;
	int no;
	string city;

	node()
	{
		next=NULL;
		city="";
		time=-1;
		no=-1;

	}
	node(string c,int w)
	{
		next=NULL;
		city=c;
		time=w;
		no=-1;
	}
	friend class flightg;
};
class flightg
{
public:
	node* head[max];
	bool visited[20]={0};
	int n;
	flightg(int num)
	{
		n=num;
		for(int i=0;i<20;i++)
		{
			head[i]=NULL;
		}

	}
	void readdata(int gt)
	{
		int i,ftime,flight;
		string city1,city2,tcity;

		cout<<"\n enter the city details"<<endl;
		for(i=0;i<n;i++)
		{
			head[i]=new node;
			cout<<"city name=:"<<i+1;
			cin>>tcity;
			head[i]->city=tcity;
			head[i]->no=i;
		}
		cout<<"\nenter the no of flights";
		cin>>flight;
		if(gt==0)
		{
		for(i=0;i<flight;i++)
		{
			cout<<"enter the source";
			cin>>city1;
			cout<<"enter the destination";
			cin>>city2;
			cout<<"enter the time";
			cin>>ftime;
			insert(city1,city2,ftime);
		}
		}
		else
		{
			for(i=0;i<flight;i++)
					{
						cout<<"enter the source";
						cin>>city1;
						cout<<"enter the destination";
						cin>>city2;
						cout<<"enter the time";
						cin>>ftime;
						insertundirected(city1,city2,ftime);
					}
		}
	}
	int index(string s)
	{
		for(int i=0;i<20;i++)
		{
			if(head[i]->city==s)
				return i;
		}
		return -1;
	}
	void insert(string city1,string city2,int ftime)
	{
		node* source;
		node* dest=new node(city2,ftime);
		int ind=index(city1);
		if(head[ind]==NULL)
			head[ind]=dest;
		else
		{
			source=head[ind];
			while(source->next!=NULL)

				source=source->next;
				source->next=dest;

		}
	}
	void insertundirected(string city1,string city2,int time)
		{
			node *source;
			node *dest=new node(city2,time);
			node *dest2=new node(city1,time);
			int ind=index(city1);
			int ind2=index(city2);
			if(head[ind]==NULL && head[ind2]==NULL)
			{
				head[ind]=dest;
				head[ind2]=dest2;
			}
			else if(head[ind]==NULL && head[ind2]!=NULL)
			{
				head[ind]=dest;
				source=head[ind2];
				while(source->next!=NULL)
					source=source->next;
				source->next=dest2;
			}
			else if(head[ind]!=NULL && head[ind2]==NULL)
			{
				head[ind2]=dest2;
				source=head[ind];
				while(source->next!=NULL)
					source=source->next;
				source->next=dest;
			}
			else
			{
				source=head[ind];
				while(source->next!=NULL)
					source=source->next;
				source->next=dest;
				//source=head[ind2];
				//while(source->next!=NULL)
					//source=source->next;
				//source->next=dest2;
			}
		}
	void outdegree()
	{
		int cnt;
		cout<<"\noutgoing flights"<<endl;
		for(int i=0;i<n;i++)
		{
			node* p=head[i]->next;
			if(p==NULL)
			{
				cout<<"there is no flight from"<<head[i]->city;
			}
			else
			{
				while(p!=NULL)
				{
					cout<<"\nsource:"<<head[i]->city<<" "<<"destination:"<<p->city<<" "<<"time:"<<p->time;
					cnt++;
					p=p->next;
				}
			}
           cout<<"\nno of outgoing flights:"<<cnt<<endl;
		}
	}
	void indegree()
	{
		int cnt[n];
		for(int i=0;i<n;i++)
			cnt[i]=0;
		cout<<"\nincoming flights"<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				node* p=head[j]->next;
				while(p!=NULL)
				{
					if(p->city==head[i]->city)
					{
                        cnt[i]=cnt[i]+1;
						cout<<"\nsource:"<<head[j]->city<<"  "<<"destination:"<<head[i]->city<<"  "<<"time:"<<p->time;

					}
					p=p->next;
				}
			}
			cout<<"\nno of incoming flights to "<<head[i]->city<<":"<<cnt[i]<<endl;
		}

	}
void dsf(int v)
{
   cout<<"DSF traversal";
	cout<<head[v]->city<<endl;
	visited[v]=1;
	for(int i=head[v]->no;i<n;i++)
	{
		if(visited[i]==0)
			dsf(i);
	}
}
};

int main()
{
	int no,ch,type;
	string c;
	cout<<"\n enter no of sations";
			cin>>no;
	cout<<"\n 0.directed 1.undirected enter type of graph";
	cin>>type;
	flightg f(no);
	f.readdata(type);
	do
	{
		cout<<"\nMenu";
		cout<<"\n1.indegree"<<"\n2.outdegree"<<"\n3.traversal";
		cout<<"\nenter your choice";
		cin>>ch;
		switch(ch)
		{
		case 1:
			f.indegree();
			break;
		case 2:
			f.outdegree();
			break;
		case 3:
			cout<<"enter the city";
			cin>>c;
			int ind=f.index(c);
			f.dsf(ind);
			break;
		}
	}while(ch<4);

}


