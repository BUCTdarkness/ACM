#include<stdio.h>
int main()
{
    int D,i,j,k;
    float t;
    while(scanf("%d",&D))
    {
        if(D<0) break;
        t=0;
        for(i=1;i<=360;i++)
            for(j=1;j<=360;j++)
                for(k=1;k<=360;k++)
                {
                    if((i-j>D||i-j<-D)&&(i-k>D||i-k<-D)&&(j-k>D||j-k<-D))
                    {
                        t++;
                    }
                }
        printf("%f\n",t);
        printf("%.3f\n",(t/(360*360*360))*100);
    }
    return 0;
}
