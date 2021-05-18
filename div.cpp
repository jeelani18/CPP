//cpp program to implement hashing using division method
#include<iostream>
using namespace std;
class HashDiv
{
int ht[10];
public:
HashDiv()
{
for(int i=0;i<10;i++)
{
ht[i]=-1;
}
}
void insert_val();
void search_val();
void delete_val();
void display_val();
};
void HashDiv::insert_val()
{
int key,val;
cout<<"Enter value to be inserted"<<endl;
cin>>val;
key=val%10;
if(ht[key]==-1)
{
ht[key]=val;
}
else
{
cout<<"position is alreay occupied"<<endl;
}
}
void HashDiv::search_val()
{
int key,val;
cout<<"Enter value to search"<<endl;
cin>>val;
key=val%10;
if(ht[key]==val)
{
cout<<"Element found at "<<key<<endl;
}
else
{
cout<<"Element not found"<<endl;
}
}
void HashDiv::delete_val()
{
int key,val;
cout<<"Enter value to be deleted"<<endl;
cin>>val;
key=val%10;
if(ht[key]==val)
{
cout<<"Deleted element is "<<ht[key]<<endl;
ht[key]=-1;
}
else
{
cout<<"Element not found"<<endl;
}
}
void HashDiv::display_val()
{
for(int i=0;i<10;i++)
{
cout<<i<<"\t";
}
cout<<endl;
for(int i=0;i<10;i++)
{
cout<<ht[i]<<"\t";
}
}
int main()
{
HashDiv hd;
int ch;
do
{
cout<<endl;
cout<<"Menu"<<endl<<"1 Insert"<<endl<<"2 Search"<<endl<<"3 
Delete"<<endl<<"4 Display"<<endl<<"5 Exit"<<endl;
cout<<"Enter your choice"<<endl;
cin>>ch;
switch(ch)
{
case 1:
hd.insert_val();
break;
case 2:
hd.search_val();
break;
case 3:
hd.delete_val();
break;
case 4:
hd.display_val();
break;
case 5:
cout<<"Exit";
break;
default:
cout<<"Invalid Choice"<<endl;
}
}while(ch!=5);
}

