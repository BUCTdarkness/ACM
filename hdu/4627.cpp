#include<stdio.h>
#define LL __int64
int main()
{
    int t;
    LL n,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        if(n==2)
        {
            printf("1\n");
            continue;
        }
        if(n%2)
        {
            printf("%I64d\n",(n/2)*(n/2+1));
            continue ;
        }
        else
        {
            s=n/2;
            if(s%2)
            {
                printf("%I64d\n",(s-2)*(s+2));
                continue;
            }
            else
            {
                printf("%I64d\n",(s-1)*(s+1));
                continue;
            }
        }
    }
    return 0;
}
