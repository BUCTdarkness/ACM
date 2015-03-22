#include<stdio.h>
int main()
{
   char ch[1000000]={0};
   int i,sum,n;
   while(scanf("%s",ch)!=EOF&&ch[0]!='0')
   {
       sum=0;
       for(i=0;ch[i]!='\0';i++)
       {
           sum+=ch[i]-'0';
       }
       while(sum>=10)
       {
           n=0;
           while(sum)
           {
              n+=sum%10;
              sum=sum/10;     
           }
           sum=n;
       }
       printf("%d\n",sum);       
   }
   return 0;
}
