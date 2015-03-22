#include<stdio.h>
#include<string.h> 
#define max 10000
int main()
{
   int n,b[max],j,i,r,length;
   char a[max],c[max];
   while(scanf("%d",&n)!=EOF)
    {
         for(j=0;j<n;j++)
         {
            scanf("%s",a);
            length=strlen(a);
            r=0;
            if(length==1) continue;
            for(i=0;i<length;i++)
            {
               b[i]=1;
            }
            //c[0]=a[0];
            for(i=0;i<length-1;i++)
            {
                //if(a[i]==a[i+1])
//                {
//                    b[r]++;
//                    c[r]=a[i];
//                    printf("%c\n",c[r]);
//                }
//                else 
//                    r++;

                 //if(a[i]==c[r])
//                     b[r]++;
//                 else
//                     {
//                        r++;
//                        c[r]=a[i];
//                        b[r]++;
//                     }             
            }
            for(i=0;i<=r;i++)
            {
                if(b[i]!=1)
                 printf("%d",b[i]);
                 printf("%c",c[i]);
            }
            printf("\n");
        }
    }
    return 0;
} 
