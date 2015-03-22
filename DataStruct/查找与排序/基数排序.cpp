//基数排序目测是懂了，就是代码还写不太利索
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int base = 10;
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
			curn=curbox[i];
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
	curn=head=new List;
	while(cin>>n)
	{
		int maxn=-10000000;
		int z=1;
		for(int i=0;i<base;i++)
		{
			curbox[i]=box[i]= new List;
		}
		for(int i=0;i<n;i++)
		{
			curn=curn->next=new List;//这句经典有木有 
			cin>>curn->num;
			maxn=max(maxn,curn->num);
		}
		while(maxn/base>0)
		{
			maxn/=base;
			z++;
		}//一位是0，两位是1
		for(int i=0;i<z;i++)
		{
			basesort(i);
		} 
		print();
	}
	return 0;
} 
