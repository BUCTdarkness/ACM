#include<iostream>
#include<string.h>
using namespace std;
typedef struct SeqList
{
	int x;
	SeqList *prior;
	SeqList *next;
}*DuLinkList;
SeqList *head;
void CreateList()
{
	head=new SeqList;
	head->prior=head;
	head->next=head;
}
DuLinkList GetElem_Dul(int i)
{
	SeqList *p;
	p=head->next;
	int j=1;
	while(p!=head&&j<i)
	{
		p=p->next;
		++j;
	}
	if(p==head&&j<i)
	{
		return NULL;
	}
	else
	{
		return p;
	}
	
}
int ListInsert_Dul(int a,int e)
{	
	SeqList *p,*s;
	if(!(p=GetElem_Dul(a)))
		return 0;
	if(!(s=new SeqList))
		return 0;
	s->x=e;
	s->prior=p->prior;
	p->prior->next=s;
	s->next=p;
	p->prior=s;
	return 1;
}
int ListDelete_Dul(int i)
{
	SeqList *p;
	if(!(p=GetElem_Dul(i)))
		return 0;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	delete p;
	return 1;
}
void show()
{
	SeqList *p;
	p=head->next;
	while(p!=head)
	{
		cout<<p->x;
		if(p->next!=head)
			cout<<" ";
		p=p->next;
	}
	cout<<endl;
}
int main()
{
	int n;
	int ord;
	CreateList();
	while(cin>>ord)
	{
		if(ord==0)
		{
			show();
		}
		if(ord==1)
		{
			int i,e;
			cin>>i>>e;
			ListInsert_Dul(i,e);
		}
		if(ord==2)
		{
			int i;
			cin>>i;
			ListDelete_Dul(i);
		}
	}
	return 0;
}
