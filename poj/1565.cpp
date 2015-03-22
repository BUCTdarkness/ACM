#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char ch[2000];
    int i,length,sum,flag,x;
    while(scanf("%s",ch)!=EOF)
    {
        length=strlen(ch);
        sum=0;
       if(strcmp(ch,"0")==0) break;
        for(i=0;i!=length;i++)
        {
           x=ch[i]-'0';
           sum+=x*(pow(2,length-i)-1);
        }
        printf("%d\n",sum);
    }
    return 0;
}
