#include<stdio.h>
int main()
{
    int n,f,i,j,num1,num2,sum,t;
    scanf("%d",&n);
    while(n--)
    {
        f=0;
        scanf("%d%d",&num1,&num2);
        if(num1>num2)
        {
           t=num1;
           num1=num2;
           num2=t;
        }
        for(i=num1;i<=num2;i++)
        {
            sum=0;
            for(j=1;j<i;j++)
            {
                if(i%j==0)
                {
                    sum+=j;
                }
            }
            if(sum==i)
               f++;
        }
        printf("%d\n",f);
    }
    return 0;
}
