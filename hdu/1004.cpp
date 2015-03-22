#include<stdio.h>
#include<string.h>
#define N 16
int main()
{
    char ch[1001][N];
    int a[1001],flag,T,max,maxnum,i,j,count=0;
    while(scanf("%d",&T)&&T)
    {
        for(i=0;i<1001;i++)
        {
           ch[i][0] = '\0';
        }
        for(i=0;i<1001;i++)
        {
           a[i]=0;
        }
        count=0;
        for(i=0;i<T;i++)
        {
           scanf("%s",ch[i]);
           flag=1;
           for(j=0;j<i;j++)
           {
               if((strcmp(ch[i],ch[j]))==0)
               {
                    ++a[j];
                    flag=0;
               }
           }
           if(flag==1)
           {
                ++a[count++];
           }
        }
        max=a[0];
        maxnum=0;
        for(i=0;i<count;i++)
        {
            if(a[i]>max)
            {
                max=a[i];
                maxnum=i;
            }
        }
        printf("%s\n",ch[maxnum]);
    }
    return 0;
}
