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
	SeqList *current,*pnext,*prev;
	current=head->next;
	pnext=current->next;
	current->next=NULL;
	while(pnext)
	{
		prev=pnext->next;
		pnext->next=current;
		current=pnext;
		pnext=prev;
	}
	head->next=current;
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
