//超时了。。。。 
#include<stdio.h>
#define max 100000
int main()
{
    int i,step,mod,seek[max],t,z,flag;
    while(scanf("%d%d",&step,&mod)!=EOF)
    {
       seek[0]=0;
       for (i=0;i<mod;i++)
       {
           seek[i]=0;
       }
       z=mod-1;
       flag=1;
       for(i=0;i<mod-1;i++)
       {
          seek[i+1]=(seek[i]+step)%mod;
       }
  while(z>=0)// 两个循环叠起来超时。。。 
       {
          t=0;
          for(i=0;i<mod;i++)
          {
             if(z==seek[i])
             {
                z--;
                t=1;
                break;
             }
          }
          if(t==0)
          {
             flag=0;
             break;
          }
       }
       printf("%d\t%d\t",step,mod);
       if(flag)
           printf("Good Choice\n");
       else
           printf("Bad Choice\n");
    }
    return 0;
}
