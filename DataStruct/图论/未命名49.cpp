#include <iostream>
using namespace std;
int map[502][502], indegree[502], m, n, pur[502];

void topsort()
{
	int i, j, k=1;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(indegree[j]==0)
			{
				indegree[j]--;
				pur[k++] = j;
				for(int x=1; x<=n; x++)
					if(map[j][x])
						indegree[x]--;
				break;
			}
			if(j>n)
			{
				cout<<"´æÔÚ»·"<<endl;
				return ;
			}
		}
	}
}

int main()
{
	int i, j;
	while(cin>>n>>m)
	{
		memset(map,0,sizeof(map));
		memset(indegree,0,sizeof(indegree));
		int a, b;
		for(i=1; i<=m; i++)
		{
			cin>>a>>b;
			if(!map[a][b])
			{
				map[a][b] = 1;
				indegree[b]++;
			}
		}
		topsort();
		for(i=1; i<=n; i++)
			if(i!=n)
				cout<<pur[i]<<" ";
			else
				cout<<pur[i]<<endl;
	}
	return 0;
}