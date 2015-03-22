#include<stdio.h>
#include<string.h>
int main()
{
    char ch[1000];
    int num,n,i,j,len;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",ch);
            len=strlen(ch);
            num=0;
            for(j=0;j<len;j++)
            {
                if(ch[j]>='0'&&ch[j]<='9')
                    num++;
            }
            printf("%d\n",num);
        }
    }
    return 0;
}
