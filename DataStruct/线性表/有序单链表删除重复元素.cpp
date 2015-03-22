#include<iostream>
using namespace std;
struct SeqList
{
	int x;
	SeqList *next;
}*head;
void CreateList(int n)
{
	head=new SeqList;
	head->next=NULL;
	SeqList *p,*q;
	p=NULL;
	q=NULL;
	for(int i=0;i<n;i++)
	{
		p=new SeqList;
		cin>>p->x;
		if(head->next==NULL)
		{
			head->next=p;
			q=p;
			p->next=NULL;
		}
		else
		{
			q->next=p;
			q=p;
		}
	}
	q->next=NULL;
}
void Change()
{
	SeqList *p;
	p=head->next;
	int m;
	m=p->x;
	while(p->next!=NULL)
	{
		if(m==p->next->x)
		{
			SeqList *q;
			q=p->next;
			p->next=q->next;
			delete q;
		}
		else
		{
			m=p->next->x;
			p=p->next;
		}
	}
}
void show()
{
	SeqList *p;
	p=head->next;
	while(p!=NULL)
		{
			cout<<p->x<<" ";
			p=p->next;
		}
		cout<<endl;
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
		{
			cout<<"list is empty"<<endl;
			continue;
		}
		CreateList(n);
		show();
		Change();
		show();
	}
	return 0;
}