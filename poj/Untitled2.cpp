#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int flag[77][77];
int w,h;
struct queue
{
	int x;
	int y;
	int dir;
	int step;
}queue[6001];

int Min(int a,int b)
{
	return a>b?b:a;
}

void Init(char a[][77])
{
	int i,j;
	for(i=1;i<=w;i++)
		for(j=1;j<=h;j++)
			if(a[i][j]=='X')
				flag[i][j]=1;
}

int BFS(int x1,int y1,int x2,int y2)
{
	int tail=1,head=1;
	int vist[77][77];
	int X,Y,i;
	int min=999999;
	for(i=0;i<=6000;i++)
		queue[i].step=99999;
	memset(vist,0,sizeof(vist));
	queue[1].x=x1;
	queue[1].y=y1;
	queue[1].dir=-1;
	queue[1].step=1;
	vist[x1][y1]=1;
	while(tail>=head)
	{
        X=queue[head].x;
		Y=queue[head++].y;
		if(X==x2-1 && Y==y2)
		{
			if(queue[head-1].dir==3 || queue[head-1].dir==-1)min=Min(min,queue[head-1].step);
			else 
			min=Min(min,queue[head-1].step+1);
		}
		else if(X==x2+1 && Y==y2)
		{
			if(queue[head-1].dir==1 || queue[head-1].dir==-1)min=Min(min,queue[head-1].step);
			else 
			min=Min(min,queue[head-1].step+1);
		}
		else if(X==x2 && Y==y2-1)
		{
			if(queue[head-1].dir==0 || queue[head-1].dir==-1)min=Min(min,queue[head-1].step);
			else 
			min=Min(min,queue[head-1].step+1);
		}
		else if(X==x2 && Y==y2+1)
		{
			if(queue[head-1].dir==2 || queue[head-1].dir==-1)min=Min(min,queue[head-1].step);
			else 
			min=Min(min,queue[head-1].step+1);
		}
		if((X-1)>=0 && Y>=0 && !flag[X-1][Y] && !vist[X-1][Y]){vist[X-1][Y]=1; queue[++tail].x=X-1; queue[tail].y=Y;
		queue[tail].dir=1;
		if(queue[head-1].dir==0 || queue[head-1].dir==2)
			queue[tail].step=Min(queue[head-1].step+1,queue[tail].step);
		else 
			queue[tail].step=Min(queue[head-1].step,queue[tail].step);
		}

		if((X+1)>=0 && Y>=0 && !flag[X+1][Y] && !vist[X+1][Y]){vist[X+1][Y]=1; queue[++tail].x=X+1; queue[tail].y=Y;
		queue[tail].dir=3;
		if(queue[head-1].dir==0 || queue[head-1].dir==2)
			queue[tail].step=Min(queue[head-1].step+1,queue[tail].step);
		else
			queue[tail].step=Min(queue[head-1].step,queue[tail].step);
		}

		if(X>=0 && (Y-1)>=0 && !flag[X][Y-1] && !vist[X][Y-1]){vist[X][Y-1]=1; queue[++tail].x=X; queue[tail].y=Y-1;
		queue[tail].dir=2;
		if(queue[head-1].dir==1 || queue[head-1].dir==3)
			queue[tail].step=Min(queue[head-1].step+1,queue[tail].step);
		else
			queue[tail].step=Min(queue[head-1].step,queue[tail].step);
		}
		if(X>=0 && (Y+1)>=0 && !flag[X][Y+1] && !vist[X][Y+1]){vist[X][Y+1]=1; queue[++tail].x=X; queue[tail].y=Y+1;
		queue[tail].dir=0;
		if(queue[head-1].dir==1 || queue[head-1].dir==3)
			queue[tail].step=Min(queue[head-1].step+1,queue[tail].step);
		else
			queue[tail].step=Min(queue[head-1].step,queue[tail].step);
		}
		cout<<"min="<<min<<endl;
	}
		
	return min;

}

int main()
{
	char aa[77][77];
	int i,j,x1,y1,x2,y2;
	int t=0,s,min;
	while(scanf("%d%d",&w,&h) && w!=0 && h!=0)
	{
		t++;
		getchar();
		memset(flag,0,sizeof(flag));
		for(i=1;i<=h;i++)
		{
			for(j=1;j<=w;j++)
				aa[j][i]=getchar();

			getchar();
		}
		Init(aa);
		for(i=0;i<=w+1;i++)
		{
			for(j=0;j<=h+1;j++)
				printf("%d ",flag[i][j]);
			printf("\n");
		}
		printf("Board #%d:\n",t);
			s=0;
		while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2) && x1!=0 && y1!=0 && x2!=0 && y2!=0)
		{
			s++;
			//printf("Pair %d: ",s);
			min=BFS(x1,y1,x2,y2);
			if(min!=999999)
				printf("Pair %d: %d segments.\n",s,min);
			else
				printf("Pair %d: impossible.\n",s);
		}

		printf("\n");
	}
return 0;
}
