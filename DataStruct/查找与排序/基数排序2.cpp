#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int base=10;
const int INF=-10000000;
struct List
{
	int num;
	List *next;
	List()
	{
		next=NULL;
	}
};
List *head,*curn,*box[base],*curbox[base];
void basesort(int t)
{
	int k=1,r,bn;
	for(int i=0;i<t;i++)
	{
		k*=base;
	}
	r=k*base;
	for(int i=0;i<base;i++)
	{
		curbox[i]=box[i];
	}
	for(curn=head->next;curn!=NULL;curn=curn->next)
	{
		bn=(curn->num%r)/k;
		curbox[bn]->next=curn;
		curbox[bn]=curbox[bn]->next;
	}
	curn=head;
	for(int i=0;i<base;i++)
	{
		if(curbox[i]!=box[i])
		{
			curn->next=box[i]->next;
			curn=curbox[bn];
		}
	}
	curn->next=NULL;
}
void print()
{
	for(curn=head->next;curn!=NULL;curn=curn->next)
	{
		cout<<curn->num<<" ";
	}
	cout<<endl;
}
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<base;i++)
		{
			curbox[i]=box[i];
		}
		int maxn=-INF;
		for(int i=0;i<n;i++)
		{
			curbox[i]=curbox[i]->next=new List;
			cin>>curbox[i]->num;
			maxn=max(maxn,curbox[i]->num);
		}
		int z=1;
		while(maxn/base)
		{
			maxn/=base;
			z++;
		}
		for(int i=0;i<z;i++)
		{
			basesort(i);
		}
		print();
	}
	return 0;
}
