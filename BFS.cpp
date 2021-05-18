//Breadth first search traversal of a graph
#include<iostream>
using namespace std;
int n,a[10][10],status[10],front=-1,rear=-1,size=10,queue[20];
class Que
{
public:
void insert(int);
int delet();
};
class BFS
{
public:
void bfs(int);
};
int main()
{
BFS b;
int i,j,v;
cout<<"Enter the no of nodes in the graph"<<endl;
cin>>n;
cout<<"Enter the adjacency matrix"<<endl;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
cin>>a[i][j];
}
}
cout<<"The adjacency matrix shown as"<<endl;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
cout<<a[i][j]<<" ";
}
cout<<endl;
}
cout<<"Enter the starting node of breadth first search"<<endl;
cin>>v;
for(i=1;i<=n;i++)
{
status[i]=1;
}
b.bfs(v);
}
void BFS::bfs(int v)
{
Que q;
int deleted,i,count=0;
q.insert(v);
while(front!=-1)
{
deleted=q.delet();
if(status[deleted]==2)
{
cout<<deleted<<" ";
status[deleted]=3;
count++;
}
for(i=n;i>=1;i--)
{
if(a[deleted][i]==1&&status[i]==1)
{
q.insert(i);
}
}
}
if(count!=n)
{
cout<<"Graph is not connected"<<endl;
}
}
void Que::insert(int vertex)
{
if(rear==size-1)
{
cout<<"Queue is overflow"<<endl;
}
else
{
rear=rear+1;
queue[rear]=vertex;
status[vertex]=2;
if(front==-1)
{
front++;
}
}
}
int Que::delet()
{
int x;
if(front==-1)
{
return -1;
}
else if(front==rear)
{
x=queue[front];
front=rear=-1;
}
else
{
x=queue[front++];
}
return x;
}

