#include<iostream>
#define MAX_LEN 300
using namespace std;
template<class T>
class queue
{
	private:
		int data[MAX_LEN];
		int head;
		int rear;
	public:
		queue()
		{
			head=rear=0;
		}
		int front()
		{
			return data[head];
		}
		void push(T t)
		{
			data[rear]=t;
			rear=(rear+1)%MAX_LEN;
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
};
struct Bank
{
	bool busy;
	int wtime;
};
struct Customer
{
	int t1;
	int t2;
	int wtime; 
};
int main()
{
	int m,total;
	while(cin>>m>>total)
	{
		Bank *bank;
		bank= new Bank[m+1];
		Customer *customer;
		customer=new Customer[total+1];
		queue <Customer> q;
		for(int i=0;i<total;i++)
		{
			cin>>customer[i].t1>>customer[i].t2;
		}
	 	for(int i=0;i<total;i++)
	 	{
	 		
	 	}
		delete []bank;
	}
	return 0;
} 
