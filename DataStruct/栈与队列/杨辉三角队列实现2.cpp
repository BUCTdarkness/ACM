#include<iostream>
#include<algorithm>
#define MAX_LEN 100000
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
			data[rear]=t;
			rear=(rear+1)%MAX_LEN;
		}
		T front()
		{
			return data[head];
		}
		void pop()
		{
			head=(head+1)%MAX_LEN;
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
			while(!this->isEmpty())
			{
				this->pop();
			}
		}
		void printQueue()
		{
			int maxc=-1;
			for(int i=this->head;i<this->rear;i++)
			{
				maxc=max(maxc,this->data[i]);
			}
			int cc=0;
			while(maxc)
			{
				maxc/=10;
				cc++;
			}
			cout<<"cc"<<cc<<endl;
			for(int i=this->head;i<this->rear;i++)
			{
				if(this->data[i]!=0)
				{
					cout<<data[i];
					int tt=0;
					int x=data[i];
					while(x)
					{
						x/=10;
						tt++;
					}
					cout<<"tt"<<tt<<endl;
					if(i!=rear-1)
					{
						for(int j=0;j<cc-tt;j++)
							cout<<" ";
					}
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
	q.printQueue();
	cout<<endl;
	if(n==1)
		return ;
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
	  	q.printQueue();
 		cout<<endl;
	}
}
int main()
{
	int m;
	while(cin>>m)
	{
		printYH(m);
	}
	return 0;
}
