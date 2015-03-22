#include<stdio.h>
#include<conio.h>
int c(int n)
{
     int i,s=1;
     for(i=1;i<=n;i++)
       s=s*i;
     return s;
}
int main()
{
    double sum=0;
    int i;
    double a;
    printf("n e\n");
    printf("- -----------\n");
    for(i=0;i<=9;i++)
    {
        a=1.0/c(i);
        sum+=a;
        if(i>2)
           printf("%d %.9lf\n",i,sum);
        else 
           if(i==2)
                printf("%d %.1lf\n",i,sum);
           else 
                printf("%d %d\n",i,(int)sum);
    }
    getch();
    return 0;
}
