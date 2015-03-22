/*
??B:??7-6:????,?????? 
??
????,??n???,????????????????????????????
??????????????,???????????
????
4
0 0 0 1
0 0 1 1
0 1 0 1
1 1 1 0
????
0 3 1 2 
*/
#include<iostream>
#include<queue>
#define MAX 55 
using namespace std;
typedef struct 
{
    int Edge[MAX][MAX];
    int EdgeNum;
}Gram;
bool isvisited[MAX];
void BuildUDG(int n)
{
    Gram g;
    g.EdgeNum=n;
    int i,j;
    for(i=0;i<g.EdgeNum;i++)
    {
        for(j=0;j<g.EdgeNum;j++)
        {
            cin>>g.Edge[i][j];
        }
    }
  /*  for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(g.Edge[i][j]==1)
            {
                cout<<i<<" "<<j<<endl;
            } 
        }
    }*/
}
void BFSsearch(int n)
{
    Gram g;
    g.EdgeNum=n;//??????????,??EdgeNum???? 
    for(int i=0;i<g.EdgeNum;i++)
    {
        isvisited[i]=false;
    }
    for(int i=0;i<g.EdgeNum;i++)
    {
        if(!isvisited[i])
        {
            queue<int> q;
            q.push(i);
            int u;
            while(!q.empty())
            {
               // cout<<"&&&&&&&&"<<endl;NO BUG! 
                u=q.front();
                q.pop();
				if(isvisited[u])
					continue;
				cout<<u<<" ";
				isvisited[u]=true;
                int k;
                for(k=0;k<g.EdgeNum;k++)
                {
                    //cout<<"^^^^^^"<<endl;NO BUG! 
                    if( g.Edge[u][k])
                    {
                        if(!isvisited[k])//BUG!!!??????,?????? 
                        {
                            q.push(k);
                        }
                    }
                } 
            } 
        }
    }       
}
int main()
{
    int n;
    cin>>n;
    BuildUDG(n);
    BFSsearch(n);
    cout<<endl; 
    system("pause");
    return 0;
}
