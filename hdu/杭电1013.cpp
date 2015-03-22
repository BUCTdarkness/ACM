#include<stdio.h>
int caculate(int n)
{
   int i,a[20];
   for(i=0;i<20;i++)
   {
      a[i]=0;
   }
   i=0;
   while(n)
   {
      a[i++]=n%10;
      n=n/10;
    }
    int r=0,sum=0;
    for(r=0;r<i;r++)
    {
        sum+=a[r];
    }
    if(sum<10)
        return sum;
    else 
         return caculate(sum);
} 
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
       printf("%d\n",caculate(n));
    }
    return 0;
}
