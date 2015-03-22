#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
int flag[100][100];
int w,h;
struct Queue
{
	int x;
	int y;
	int dir;
	int steps;
}queue[6001];
int Min(int a,int b)
{
    return a>b?b:a;
}
void initialize(char aa[][77])
{
	int i,j;
	cout<<"sssss"<<endl;
	for(i=1;i<=w;i++)
         for(j=1;j<=h;j++)
         cout<<aa[i][j];
    cout<<endl;
	for(i=1;i<=w;i++)
		for(j=1;j<=h;j++)
			if(aa[i][j]=='X')
				flag[i][j]=1;
}
int bfs(int x1,int y1,int x2,int y2)
{
	int head=1,tail=1;
	int vis[77][77];
	int min=999999;
	int X,Y,i;
	memset(vis,0,sizeof(vis));
	for(i=0;i<=6000;i++)
	{
		queue[i].steps=999999;
	}
	queue[1].x=x1;
	queue[1].y=y1;
	queue[1].dir=-1;
	queue[1].steps=1;
	vis[x1][y1]=1;
	while(head<=tail)
	{
        X=queue[head].x;
		Y=queue[head++].y;
		if(X==x2-1&&Y==y2)
		{
			if(queue[head-1].dir==3||queue[head-1].dir==-1)
			{
				min=Min(min,queue[head-1].steps);
			}
			else
				min=Min(min,queue[head-1].steps+1);
		}
		else if(X==x2+1&&Y==y2)
		{
			if(queue[head-1].dir==1||queue[head-1].dir==-1)
			{
				min=Min(min,queue[head-1].steps);
			}
			else
				min=Min(min,queue[head-1].steps+1);		
		}
		else if(X==x2&&Y==y2-1)
		{
			if(queue[head-1].dir==0||queue[head-1].dir==-1)
			{
				min=Min(min,queue[head-1].steps);
			}
			else
				min=Min(min,queue[head-1].steps+1);
		}
		else if(X==x2&&Y==y2+1)
		{
			if(queue[head-1].dir==2||queue[head-1].dir==-1)
			{
				min=Min(min,queue[head-1].steps);
			}
			else
				min=Min(min,queue[head-1].steps+1);
		}
if((X-1)>=0 && Y>=0 && !flag[X-1][Y] && !vis[X-1][Y]){vis[X-1][Y]=1; queue[++tail].x=X-1; queue[tail].y=Y;
		queue[tail].dir=1;
		if(queue[head-1].dir==0 || queue[head-1].dir==2)
			queue[tail].steps=Min(queue[head-1].steps+1,queue[tail].steps);
		else 
			queue[tail].steps=Min(queue[head-1].steps,queue[tail].steps);
		}

		if((X+1)>=0 && Y>=0 && !flag[X+1][Y] && !vis[X+1][Y]){vis[X+1][Y]=1; queue[++tail].x=X+1; queue[tail].y=Y;
		queue[tail].dir=3;
		if(queue[head-1].dir==0 || queue[head-1].dir==2)
			queue[tail].steps=Min(queue[head-1].steps+1,queue[tail].steps);
		else
			queue[tail].steps=Min(queue[head-1].steps,queue[tail].steps);
		}

		if(X>=0 && (Y-1)>=0 && !flag[X][Y-1] && !vis[X][Y-1]){vis[X][Y-1]=1; queue[++tail].x=X; queue[tail].y=Y-1;
		queue[tail].dir=2;
		if(queue[head-1].dir==1 || queue[head-1].dir==3)
			queue[tail].steps=Min(queue[head-1].steps+1,queue[tail].steps);
		else
			queue[tail].steps=Min(queue[head-1].steps,queue[tail].steps);
		}
		if(X>=0 && (Y+1)>=0 && !flag[X][Y+1] && !vis[X][Y+1]){vis[X][Y+1]=1; queue[++tail].x=X; queue[tail].y=Y+1;
		queue[tail].dir=0;
		if(queue[head-1].dir==1 || queue[head-1].dir==3)
			queue[tail].steps=Min(queue[head-1].steps+1,queue[tail].steps);
		else
			queue[tail].steps=Min(queue[head-1].steps,queue[tail].steps);
		}
		cout<<"min="<<min<<endl;
		getch();
	}
	return min;
}
int main(void)
{
	int n=1,w,h,min;
	int t=0,s,i,j,x1,y1,x2,y2;
	char aa[77][77];
	while(cin>>w>>h&&w!=0&&h!=0)
	{
        t++;
        getchar();
        memset(flag,0,sizeof(flag));
		for(int i=1;i<=h;i++)
		{
             for(int j=1;j<=w;j++)
                 aa[j][i]=getchar();
             getchar();
        }
        cout<<endl;
        for(int i=1;i<=w;i++)
                for(int j=1;j<=h;j++)
                        cout<<aa[i][j];
        cout<<endl;
			for(i=1;i<=w;i++)
		for(j=1;j<=h;j++)
			if(aa[i][j]=='X')
				flag[i][j]=1;
				for(i=0;i<=w+1;i++)
		{
			for(j=0;j<=h+1;j++)
				printf("%d ",flag[i][j]);
			printf("\n");
		}
		cout<<"Board #"<<t<<":"<<endl;
		s=0;
		while(cin>>x1>>y1>>x2>>y2&&x1!=0&&y1!=0&&x2!=0&&y2!=0)
		{
            s++;
            min=bfs(x1,y1,x2,y2);
			cout<<"Pair "<<s<<": ";
			if(min!=999999)
				cout<<min<<" segments."<<endl;
			else
				cout<<"impossible."<<endl;
		}
		cout<<endl;
	}
	getch();
	return 0;
}
