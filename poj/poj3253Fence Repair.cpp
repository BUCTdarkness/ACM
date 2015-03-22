#include<iostream>
using namespace std;
struct HaffmanTree
{
	int weight;
	int parent;
	int leftchild;
	int rightchild;
};
HaffmanTree t[20000];
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>t[i].weight;
			t[i].parent=-1;
		}
		int m=n+n-1,sum=0;
		for(int i=n;i<m;i++) 
		{
			t[i].parent=-1;
			t[i].leftchild=-1;
			t[i].rightchild=-1;
		}
		for(int i=n;i<m;i++)
		{
			int min1=50001,min2=50001,pos1=-1,pos2=-1;
			for(int j=0;j<i;j++)
			{
				if(t[j].parent==-1)
				{
					if(t[j].weight<min1)
					{
						pos2=pos1;
						min2=min1;
						pos1=j;
						min1=t[j].weight;
					}
					else if(t[j].weight<min2)
					{
						pos2=j;
						min2=t[j].weight;
					}
				}
			}
			t[i].leftchild=pos1;
			t[i].rightchild=pos2;
			t[i].weight=t[pos1].weight+t[pos2].weight;
			cout<<t[i].weight<<endl;
			cout<<"ssssss"<<endl;
			sum+=t[i].weight;
			t[pos1].parent=t[pos2].parent=i;
		}
		cout<<sum<<endl;
	}
	return 0;
}