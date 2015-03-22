#include<iostream>
#include<string.h>
using namespace std;
typedef struct Node
{
	int coef,expn;
	struct Node *next;
}Node,*SeqList;
void AddPolyn(SeqList &Pa,SeqList &Pb)
{
	SeqList ha,qa,qb;
	ha=Pa;
	qa=Pa->next;
	qb=Pb->next;
	while(qa&&qb)
	{
		if(qa->expn<qb->expn)
		{
			SeqList b;
			b=qb;
			qb=qb->next;
			ha->next=b;
			b->next=qa;
			ha=ha->next;
			
		}
		else if(qa->expn==qb->expn)
			{
				if(qa->coef+qb->coef!=0)
				{
					qa->coef+=qb->coef;
					qa=qa->next;
					qb=qb->next;
					ha=ha->next;
				}
				else
				{
					SeqList a,b;
					a=qa;
					qa=qa->next;
					ha->next=qa;
					delete a;
					b=qb;
					qb=qb->next;
					delete b;
				}
			}
			else
			{
				ha=ha->next;
				qa=qa->next;
			}	
	}
	if(qb)
	{
		ha->next=qb;
	}
}
void print(SeqList &Pa)
{
	SeqList p;
	p=Pa->next;
	while(p)
	{
		cout<<p->coef<<" "<<p->expn<<" ";
		p=p->next;
	}
	cout<<endl;
}
int main()
{
	SeqList Pa,Pb,q,p;
	char *k,str[300];
	Pa=new Node;
	Pb=new Node;
	while(gets(str))
	{
		p=Pa;
		k=strtok(str," ");
		while(k!=NULL)
		{
			q=new Node;
			q->coef=(int)atof(k);
			k=strtok(NULL," ");
			q->expn=(int)atof(k);
			k=strtok(NULL," ");
			p->next=q;
			p=p->next;
		}
		p->next=NULL;
		gets(str);
		p=Pb;
		k=strtok(str," ");
		while(k!=NULL)
		{
			q=new Node;
			q->coef=(int)atof(k);
			k=strtok(NULL," ");
			q->expn=(int)atof(k);
			k=strtok(NULL," ");
			p->next=q;
			p=p->next;
		}
		p->next=NULL;
		AddPolyn(Pa,Pb);
		print(Pa);
	}
	return 0;
}