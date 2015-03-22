#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAX=105;
int mat[MAX][MAX];
int main()
{
    int T;
    while(cin>>T)
    {
        for(int kase=1;kase<=T;kase++)
        {
            int N;
            cin>>N;
            for(int i=1;i<=N;i++)
            {
                for(int j=1;j<=N;j++)
                {
                    scanf("%d",&mat[i][j]);
                }
            }
            int ans=N*(N-1);
            for(int i=1;i<=N;i++)
            {
                for(int j=1;j<=N;j++)
                {
                    for(int k=1;k<=N;k++)
                    {
                        if(i==k||j==k||i==j)
                            continue;
                        if(mat[i][k]+mat[k][j]<mat[i][j])
                        {
                            ans=-1;
                            break;
                        }
                        if(mat[i][k]+mat[k][j]==mat[i][j])
                        {
                            ans--;
                            break;
                        }
                    }
                    if(ans<0)
                        break;
                }
                if(ans<0)
                    break;
            }
            cout<<"Case "<<kase<<": ";
            if(ans<0)
            {
                cout<<"impossible"<<endl;
            }
            else
            {
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}

