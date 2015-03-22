#include<iostream>
#include<string.h>
using namespace std;
struct SeqList
{
	char name[40];
	SeqList *next;
}*l,*head;
void insert(int a,char *nam)
{	

	SeqList *p;
	p=new SeqList;
	strcpy(p->name,nam);
	l=head;
	if(a==1)
	{
		if(head==NULL)
		{
			head=p;
			l=head;
			l->next=NULL;
		}
		else
		{
			p->next=head;
			head=p;
			l=head;
		}
	}
	else
	{
		for(int i=0;i<a-2;i++)
		{
			l=l->next;
		}
		p->next=l->next;
		l->next=p;
		l=head;
	}
}
void show()
{
	l=head;
	if(head==NULL)
	{
		cout<<endl;
	}
	else
	{
		while(l!=NULL)
		{
			cout<<l->name;
			if(l->next!=NULL)
				cout<<" ";
			l=l->next;
		}
		cout<<endl;
	}
	l=head;
}
void remove(char *nam)
{
	l=head;
	if(strcmp(nam,head->name)==0)
	{
		SeqList *p;
		p=head;
		head=head->next;
		delete p;
		l=head;
	}
	else
	{
		while(l!=NULL)
		{
			if(strcmp(nam,l->next->name)==0)
			{
				SeqList *p;
				p=l->next;
				l->next=p->next;
				delete p;
				l=head;
				break;
			}
			l=l->next;
		}
	}
}
void search(char *nam)
{
	l=head;
	int n=1;
	while(l!=NULL)
	{
		if(strcmp(nam,l->name)==0)
		{
			cout<<n<<endl;
			break;
		}
		l=l->next;
		n++;
	}
}
int main()
{
	char ch[100],name[40];
	int a;
	l=head=NULL;
	while(cin>>ch)
	{
		if(ch[0]=='i')
		{
			cin>>a>>name;
			insert(a,name);	
		}
		if(ch[0]=='s'&&ch[1]=='h')
		{
			show();
		}
		if(ch[0]=='d')
		{
			cin>>name;
			remove(name);
		}
		if(ch[0]=='s'&&ch[1]=='e')
		{
			cin>>name;
			search(name);
		}
	}
	return 0;
}
