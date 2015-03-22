#include<stdio.h>
int main()
{
    int n,u,d,step,minute;
    while(scanf("%d%d%d",&n,&u,&d)!=EOF)
    {
        if(n==0&&u==0&&d==0)
            break;
        step=0;
        minute=0;
        while(step<n)
        {
            step+=u;
            minute+=1;
            if(step>=n)  break;
            step-=d;
            minute+=1;
        }
        printf("%d\n",minute);
    }
    return 0;
}
