#include <iostream>
using namespace std; 
typedef struct Node
{
   int data;
   int length;
   struct Node *next;
}NODE,*PNODE;

void creat_list(int len,PNODE pHead)
{
   int i;
   int val;
   PNODE pTail=pHead;
   pTail->next=NULL;
   for(i=0;i<len;i++)
   {
       cin >> val;
       PNODE pNew=new Node;
       pNew->data=val;
       pTail->next=pNew;
       pNew->next=NULL;
       pTail=pNew; 
   }
}
void traverse_list(PNODE pHead)
{
     PNODE p=pHead->next;
     while(p!=NULL)
     {
            cout << p->data << " " ;
            p=p->next; 
           
     }
     cout << endl; 
}
PNODE del(PNODE pHead)
{
   	PNODE p,q,r;
	p=pHead->next;
	int m=p->data;
	while(p->next!=NULL)
	{
		if(m==p->next->data)
		{
			q=p->next;
			p->next=q->next;
			delete q;
		}
		else
		{
			m=p->next->data;
			p=p->next;
		}
	}
   	return pHead;
}
int main()
{
    int k;
    while(cin >>k)
    {                               
     if(k==0)
        {
                cout << "list is empty "<< endl;
                continue;
        }
        PNODE pHead=new Node;
        pHead->next=NULL;
        creat_list(k,pHead);
        traverse_list(pHead);
        del(pHead);
        traverse_list(pHead);
    }
    return 0;
}
