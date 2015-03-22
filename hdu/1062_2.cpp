#include<stdio.h>
#include<string.h>
int main()
{
    int T,i,j,z,k,n;
    char ch[1002];
    scanf("%d",&T);
    getchar();
    for(i=0;i<T;i++)
    {
        gets(ch);
        n=strlen(ch);
        ch[n]=' ';
        ch[n+1]='\0';
        k=0;
        for(j=0;j<=n;j++)
        {
            if(ch[j]==' ')
            {
                for(z=j-1;z>=k;z--)
                {
                    printf("%c",ch[z]);
                }
                if(z!=n)
                    printf(" ");
                k=j+1;
            }
        }
        printf("\n");
        memset(ch,0,n);
    }
    return 0;    
}
