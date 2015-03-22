#include<iostream>
#include<string.h>
using namespace std;
int c;
void move(char x,int n,char z)
{
	printf("%2d. Move disk %d from %c to %c\n",++c,n,x,z);
}
void hanoi(int n,char x,char y,char z)
{
	if(n==1) 
		move(x,1,z);
	else                                  
	{
		hanoi(n-1,x,z,y);                  
		move(x,n,z);
		hanoi(n-1,y,x,z);
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		c=0;
		char x='X',y='Y',z='Z';
		hanoi(n,x,y,z);
		printf("\n");
	}
	return 0;
}
