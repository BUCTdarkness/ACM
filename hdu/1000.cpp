#include<stdio.h>
#include<string.h>
int main()
{
    int a[1002]={0},b[1002]={0},c[1002]={0};
    char str1[1002],str2[1002];
    int n,j,len1,len2,len,r=0;
    scanf("%d",&n);
    while(n--)
    {
        if(r>0) printf("\n");
        scanf("%s",str1);
        scanf("%s",str2);
        len1=strlen(str1);
        len2=strlen(str2);
        for(j=0;j<len1;j++)
           a[j]=str1[len1-j-1]-'0';
        for(j=0;j<len2;j++)
           b[j]=str2[len2-j-1]-'0';
        len=len1>len2?len1:len2;
        for(j=0;j<len;j++)
        {
             c[j]=a[j]+b[j]+c[j];
             c[j+1]=c[j]/10;
             c[j]=c[j]%10;
        }
        if(c[j]) len++;
        r++;
        printf("Case %d:\n",r);
        printf("%s + %s = ",str1,str2);
        for(j=len-1;j>=0;j--)
            printf("%d",c[j]);
        printf("\n");
       for(j=0;j<len1;j++) a[j]=0;
       for(j=0;j<len2;j++) b[j]=0;
       for(j=0;j<len;j++)  c[j]=0;
    }
    return 0;
}
