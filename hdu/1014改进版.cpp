//这个算法跟产生不同随机数的算法相似。。 
#include<stdio.h>
#define max 100000
int main()
{
    int i,step,mod,seek[max],result[max];
    while(scanf("%d%d",&step,&mod)!=EOF)
    {
       seek[0]=0;
       for (i=0;i<mod;i++)
       {
           seek[i]=0;
           result[i]=0;
       }
       for(i=0;i<mod-1;i++)
       {
          seek[i+1]=(seek[i]+step)%mod;
          result[seek[i+1]]=seek[i+1];
       }
       for(i=1;i<mod;i++)
       {
          if(result[i]!=i)
             break;
       }
       if(i>=mod-1)
       
           printf("%10d%10d    Good Choice\n\n",step,mod);
       else
           printf("%10d%10d    Bad Choice\n\n",step,mod);
    }
    return 0;
}
