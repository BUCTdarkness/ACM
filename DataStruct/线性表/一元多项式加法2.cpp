#include<iostream>
#include<string.h>
using namespace std;
#define MAXN 3000
int c[MAXN];
char ch[3010],*ch1;
struct SeqList
{
	int x;
	int y;
	SeqList *next;
}*head1,*head2,*head3;
int change(char *ch)
{
	int len=strlen(ch);
	int x=0,h=1;
	if(ch[0]!='-')
	{
		for(int i=len-1;i>=0;i--)
		{
			x+=(ch[i]-'0')*h;
			h*=10;
		}
	}
	else
	{
		for(int i=len-1;i>=1;i--)
		{
			x+=(ch[i]-'0')*h;
			h*=10;
		}
		x=-x;
	}
	return x;
}
void CreateList1(int n,int c[])
{
	SeqList *p;
	int i;
	head1=new SeqList;
	head1->next=NULL;
	for(int i=n-1;i>=1;i--)
	{
		p=new SeqList;
		p->x=c[i-1];
		p->y=c[i];
		i--;
		p->next=head1->next;
		head1->next=p;
	}
}
void CreateList2(int n,int c[])
{
	SeqList *p;
	int i;
	head2=new SeqList;
	head2->next=NULL;
	for(int i=n-1;i>=1;i--)
	{
		p=new SeqList;
		p->x=c[i-1];
		p->y=c[i];
		i--;
		p->next=head2->next;
		head2->next=p;
	}
}
void CreateList3(int n,int c[])
{
	SeqList *p;
	int i;
	head3=new SeqList;
	head3->next=NULL;
	for(int i=n-1;i>=1;i--)
	{
		p=new SeqList;
		p->x=c[i-1];
		p->y=c[i];
		i--;
		p->next=head3->next;
		head3->next=p;
	}
}
void show(SeqList *head)
{
	SeqList *p;
	p=head->next;
	if(p==NULL) cout<<"0";
	while(p!=NULL)
	{
		cout<<p->x;
		cout<<" ";
		cout<<p->y;
		cout<<" ";
		p=p->next;
	}
	cout<<endl;
}
int main()
{
	while(gets(ch))
	{
		memset(c,0,sizeof(c));
		ch1=strtok(ch," ");
		int k=0;
		while(ch1!=NULL)
		{
			c[k++]=change(ch1);
			ch1=strtok(NULL," ");		
		}
		int len1=k;
		CreateList1(k,c);
		gets(ch);
		ch1=strtok(ch," ");
		k=0;
		memset(c,0,sizeof(c));
		while(ch1!=NULL)
		{
			c[k++]=change(ch1);
			ch1=strtok(NULL," ");		
		}
		int len2=k;
		CreateList2(k,c);
		memset(c,0,sizeof(c));
		int i=1,j=1;
		k=0;
		SeqList *p1,*p2;
		p1=head1->next;
		p2=head2->next;
		int flag=0;
		while(i<=len1/2&&j<=len2/2)
		{
			flag=0;
			if(p1->y>p2->y)
			{
				i++;
				c[k++]=p1->x;
				c[k++]=p1->y;
				if(i<=len1/2)
				{
					p1=p1->next;
				}
			}
			else 
				if(p2->y>p1->y)
				{
					j++;
					c[k++]=p2->x;
					c[k++]=p2->y;
					if(j<=len2/2)
						p2=p2->next;
				}
				else
				{
					int tot=p1->x+p2->x;
					if(tot)
					{
						c[k++]=tot;
						c[k++]=p1->y; 
					}
					i++;
					j++;
					flag=1;
					if(i<=len1/2&&j<=len2/2)
					{
						p1=p1->next;
						p2=p2->next;
					}
				}
		}
		while(i<=len1/2)
		{
			if(flag)
				p1=p1->next;
			c[k++]=p1->x;
			c[k++]=p1->y;
			i++;
			p1=p1->next; 
		}
		while(j<=len2/2)
		{
			if(flag)
				p2=p2->next;
			c[k++]=p2->x;
			c[k++]=p2->y;
			j++;
			p2=p2->next;
		}
		CreateList3(k,c);
		show(head3);
	}
	return 0;
}
