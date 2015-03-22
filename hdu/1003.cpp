#include<stdio.h>
int main()
{
    int i,j,T,N,num;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
         int max=-1001,sum=0,t=1,startp=0,endp=0;
         scanf("%d",&T);
         for(j=1;j<=T;j++)
         {
             scanf("%d",&num);
             sum=sum+num;
             if(sum>max)
             {
                  max=sum;
                  startp=t;
                  endp=j;                  
             }
             if(sum<0)
             {
                  sum=0;
                  t=j+1;
             }            
         }
         printf("Case %d:\n",i+1);
         printf("%d %d %d\n",max,startp,endp);
         if(i<N-1) printf("\n");
    }
    return 0;
}
