#include<stdio.h>
int main()
{
    int b,time,floor,n;
    while(scanf("%d",&n)!=EOF)
        {
            if(n==0) 
                break;
            b=0;
            time=0;
            while(n--)
                 {
                      scanf("%d",&floor);
                      if(floor-b>=0)
                          time+=(floor-b)*6+5;
                      else  if(floor-b<0)
                                time+=(b-floor)*4+5;
                      b=floor;
                 }
            printf("%d\n",time);
        }
    return 0;
}
