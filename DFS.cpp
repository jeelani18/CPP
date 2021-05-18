/*Depth First Search Traversal of Graph*/
#include<iostream>
using namespace std;
int n,a[10][10],status[10];
int top=-1,size=10,stack[20];
class stk
{
public:
void push(int vertex)
{
if(top==size-1)
{
cout<<"stack is overflow";
}
else
{
top=top+1;
stack[top]=vertex;
status[vertex]=2;
}
}
int pop()
{
if(top==-1)
return(-1);
else
{
return (stack[top--]);
}
}
};
class DFS
{
public:
void dfs(int v)
{
stk s;
int poped,i,count=0;
s.push(v);
while(top!=-1)
{
poped=s.pop();
if(status[poped]==2)
{
cout<<poped<<"\t";
count++;
status[poped]=3;
}
for(i=n;i>=1;i--)
{
if(a[poped][i]==1 && status[i]==1)
{
s.push(i);
}
}
}
if(n!=count)
cout<<"\nGraph is not connected";
}
};
int main()
{
int i,j,v;
DFS d;
cout<<"Enter the no. of node in the graph\n";
cin>>n;
cout<<"Enter adjacency matrix\n";
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
cin>>a[i][j];
}
}
cout<<"The adjacency matrix is shown as\n";
 for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
cout<<a[i][j]<<"\t";
}
cout<<"\n";
}
cout<<"Enter the starting node for Dep[th first search\n";
cin>>v;
for(i=1;i<=n;i++)
 status[i]=1;
d.dfs(v) ;
}

