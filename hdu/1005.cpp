#include<stdio.h>
#include<conio.h>
int f[100000000];
int caculate(int A,int B,int n)
{
    f[1]=1;
    f[2]=1;
    if(n==1||n==2)
       return 1;
    else 
       {
              f[n]=caculate(A,B,n-1);    
              return (A*f[n]+B*f[n-1])%7;
       }
}
int main()
{
    int A,B,n,y;
    scanf("%d%d%d",&A,&B,&n);
    while(A||B||n)
    {
       y=caculate(A,B,n);
       printf("%d\n",y);
       scanf("%d%d%d",&A,&B,&n);
    }
    getch();
    return 0;
}
