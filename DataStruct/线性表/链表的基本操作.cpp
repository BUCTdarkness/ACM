#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
struct SeqList
{
	int x;
	SeqList *next;
};
SeqList *head;
void CreateList(int n)
{
	SeqList *p;
	int i;
	head=new SeqList;
	head->next=NULL;
	for(int i=n;i>0;--i)
	{
		p=new SeqList;
		cin>>p->x;
		p->next=head->next;
		head->next=p;
	}
}
void GetElem(int i)
{
	SeqList *p;
	p=head->next;
	int j=1;
	while(p&&j<i)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i)
	{
		cout<<"get fail"<<endl;
		return ;
	}
	else
	{
		cout<<p->x<<endl;
	}
	
}
void ListInsert(int a,int e)
{	
	SeqList *p,*s;
	p=head;
	int j=0;
	while(p!=NULL&&j<a-1)
	{
		p=p->next;
		++j;
	} 
	if(p==NULL||j>a-1)
	{
		cout<<"insert fail"<<endl;
		return;
	}
	s=new SeqList;
	s->x=e;
	s->next=p->next;
	p->next=s;
	cout<<"insert OK"<<endl;
}
void ListDelete(int i)
{
	SeqList *p,*q;
	p=head;
	int j=0;
	while(p->next!=NULL&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(p->next==NULL||j>i-1)
	{
		cout<<"delete fail"<<endl;
		return;
	}
	q=p->next;
	p->next=q->next;
	delete q;
	cout<<"delete OK"<<endl;
}
void show()
{
	SeqList *p;
	p=head->next;
	if(p==NULL)
	{
		cout<<"Link list is empty"<<endl;
	}
	else
	{
		cout<<p->x;
		p=p->next;
		while(p!=NULL)
		{
			cout<<" ";
			cout<<p->x;
			p=p->next;
		}
		cout<<endl;
	}
}
int main()
{
	int n;
	char ord[10];
/*
	freopen("seqlist-in.txt","r",stdin);
	freopen("seqlist.txt","w",stdout);*/
	while(cin>>n)
	{
		memset(ord,'\0',sizeof(ord));
		CreateList(n);
		show();
		getch();
		int m;
		cin>>m;
		while(m--)
		{
			cin>>ord; 
			if(strcmp(ord,"get")==0)
			{
				int a;
				cin>>a;
				GetElem(a);
			}
			if(strcmp(ord,"insert")==0)
			{
				int a,e;
				cin>>a>>e;
				ListInsert(a,e);
			}
			if(strcmp(ord,"delete")==0)
			{
				int a;
				cin>>a;
				ListDelete(a);
			}
			if(strcmp(ord,"show")==0)
			{
				show();
			}
		}
	}
	return 0;
}

