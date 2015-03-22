#include<iostream>
#include<conio.h>
#define MAX_LEN 100
using namespace std;
template <class T>
class queue
{
	private:
		T data[MAX_LEN];
		int head;
		int rear;
	public:
		queue()
		{
			head=0;
			rear=0;
		}
		void push(T t)
		{
			data[rear++]=t;
		}
		T front()
		{
			return data[head];
		}
		void pop()
		{
			head++;
		}
		bool isEmpty()
		{
			if(head==rear)
				return true;
			else
				return false;
		}
		void clear()
		{
			while(!isEmpty())
			{
				this->pop();
			}
		}
		void printQueue()
		{
			for(int i=this->head;i<this->rear;i++)
			{
				if(this->data[i]!=0)
				{
					cout<<data[i];
					if(i!=rear-1)
					cout<<" ";
				}
			}
		}
};
void printYH(int n)
{
	queue<int> q;
	q.push(0);
	q.push(1);
	q.push(0);
	int s,t,i;
	for(i=2;i<=n;i++)
	{
 		do
 		{
		 	s=q.front();
		 	q.pop();
		 	t=q.front();
		 	q.push(s+t);
		 }while(t!=0);
		 q.push(0);
	}
 	q.printQueue();
 	cout<<endl;
}
int main()
{
	int n;
	while(cin>>n)
	{

			for(int i=1;i<=n;i++)
			{
			 	printYH(i);
			}
	}
	return 0;
}





