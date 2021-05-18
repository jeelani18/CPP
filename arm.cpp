#include<iostream>
using namespace std;

int main()
{
int no,rem,sum=0,temp;
cout<<"enter number: ";
cin>>no;
temp=no;
while(no!=0)
{
	rem=no%10;
	sum=sum+(rem*rem*rem);
	no=no/10;
}
if (sum==temp)
{

	cout<<"its armstrong";
}
else{

	cout<<"not armstrong";
}
return 0;
}

/*int main()
{
int no,r,sum=0,temp;
cout<<"enter number: ";
cin>>no;
temp=no;
while(no!=0)
{
	r=no%10;
	sum=sum*10+r;
	no=no/10;
}
if (sum==temp)
{
	cout<<"palindrome";
}
else
{
	cout<<"no";
}
return 0;
}
*/
