//HaffmanTree !!!!!

#include<iostream>
#define MAX_LEN 1000+10
using namespace std;
struct HaffmanTree
{
	int parent;
	int weight;
}data[MAX_LEN];
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>data[i].weight;
			data[i].parent=-1;
		}
		int m=n+n+1;
		__int64 ans=0;
		for(int i=n;i<m;i++)
		{
			data[i].parent=-1;
		}
		for(int i=n;i<m;i++)
		{
			int min1=55555,min2=55555;
			int pos1=-1,pos2=-1;
			for(int j=0;j<i;j++)
			{
				if(data[j].parent==-1)
				{
					if(data[j].weight<min1)
					{
						pos2=pos1;
						min2=min1;
						pos1=j;
						min1=data[j].weight;
					}
					else if(data[j].weight<min2)
						{
							min2=data[j].weight;
							pos2=j;
						}
				}
			}
			if(pos1>=0&&pos2>=0)
			{
			data[i].weight=data[pos1].weight+data[pos2].weight;
			ans+=data[i].weight;
			data[pos1].parent=data[pos2].parent=i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}



