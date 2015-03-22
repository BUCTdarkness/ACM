#include<stdio.h>
int main()
{
    int A,B,n,i,f[50];
    while(scanf("%d%d%d",&A,&B,&n)&&A&&B&&n)
    {
         for(i=0;i<50;i++)
         {
             f[0]=1;
             f[1]=1;
             f[i]=(A*f[i-1]+B*f[i-2])%7;
             if(i>4&&f[i]==f[2]&&f[i-1]==f[1]&&f[i-2]==f[0])
                 break;
         }
         n=n%(i-2);
         if(n==0) 
              n=i-3;
         else
             n--;
        printf("%d\n",f[n]);
    }
    return 0;
}
