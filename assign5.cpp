#include <iostream>
#include<iomanip>
using namespace std;

const int MAX=10;
class EdgeList;  
class Edge  
{
 int u,v,w;
public:
 Edge(){}
 Edge(int a,int b,int weight)
 {
  u=a;
  v=b;
  w=weight;
 }
 friend class EdgeList;
 friend class PhoneGraph;
};

class EdgeList
{
 Edge data[MAX];
 int n;
public:
 friend class PhoneGraph;
 EdgeList()
 { n=0;}
 void sort();
 void print();

};
void EdgeList::sort()
{
 Edge temp;
 for(int i=1;i<n;i++)
  for(int j=0;j<n-1;j++)
   if(data[j].w>data[j+1].w)
   {
    temp=data[j];
    data[j]=data[j+1];
    data[j+1]=temp;
   }
}
void EdgeList::print()
{
 int cost=0;
 for(int i=0;i<n;i++)
 {
  cout<<"\n"<<i+1<<" "<<data[i].u<<"--"<<data[i].v<<" = "<<data[i].w;
  cost=cost+data[i].w;
 }
 cout<<"\nMinimum cost of Telephone Graph = "<<cost;
}

class PhoneGraph
{
 int data[MAX][MAX];
 int n;

public:
 PhoneGraph(int num)
{
  n=num;
}
 void readgraph();
 void printGraph();
 void kruskal(EdgeList &spanlist);
 int find(int belongs[], int vertexno);
 void unionComp(int belongs[], int c1,int c2);
};
void PhoneGraph::readgraph()
{
 cout<<"Enter Adjacency(Cost) Matrix: \n";
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n; j++)
   cin>>data[i][j];
 }
}
void PhoneGraph::printGraph()
{
 cout<<"\nAdjacency (COST) Matrix: \n";
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
  {
   cout<<setw(3)<<data[i][j];
  }
  cout<<endl;
 }
}


void PhoneGraph::kruskal(EdgeList &spanlist)
{
 int belongs[MAX];
 int cno1,cno2; 
 EdgeList elist;
 for(int i=1;i<n;i++)
  for(int j=0;j<i;j++)
  {
   if(data[i][j]!=0)
   {
    elist.data[elist.n]=Edge(i,j,data[i][j]); 
    elist.n++;
   }
  }
 elist.sort(); 
 for(int i=0;i<n;i++)
  belongs[i]=i;

 for(int i=0;i<elist.n;i++)
 {
  cno1=find(belongs,elist.data[i].u); 
  cno2=find(belongs,elist.data[i].v); 
  if(cno1!=cno2) 
  {
   spanlist.data[spanlist.n]=elist.data[i]; 
   spanlist.n=spanlist.n+1;
   unionComp(belongs,cno1,cno2); 
  }
 }
}
void PhoneGraph::unionComp(int belongs[],int c1,int c2)
{
 for(int i=0;i<n;i++)
 {
  if(belongs[i]==c2)
   belongs[i]=c1;
 }
}
int PhoneGraph::find(int belongs[],int vertexno)
{
 return belongs[vertexno];
}

//--------- MAIN PROGRAM-----------------------------------
int main() {
 int vertices,choice;
 EdgeList spantree;
 cout<<"Enter Number of cities: ";
 cin>>vertices;
 PhoneGraph p1(vertices);
 p1.readgraph();
 do
 {
  cout<<"\n1.Find Minimum Total Cost(by Kruskal's Algorithms)"
    <<"\n2.Re-Read Graph(INPUT)"
    <<"\n3.Print Graph"
    <<"\n0. Exit"
    <<"\nEnter your choice: ";
  cin>>choice;
  switch(choice)
  {
  case 1:
   p1.kruskal(spantree);
   spantree.print();
   break;
  case 2:
   p1.readgraph();
   break;
  case 3:
   p1.printGraph();
   break;
  default:
   cout<<"\nWrong Choice!!!";
  }
 }while(choice!=0);

 return 0;
}
