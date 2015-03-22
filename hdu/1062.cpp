#include<stdio.h>
#include<string.h>
int main()
{
    scanf("%d",&T);
    getchar();
    for(i=0;i<T;i++)
    {
        gets(ch);
        n=strlen(ch);
        ch[n]=' ';
        ch[n+1]='\0';
        for(j=0;j<n;j++)
        {
            k=0;
            if(ch[j]==' ')
            {
                for(z=j-1;z>=k;z--)
                {
                    printf("%c",ch[z]);
                }
                if(z!=n)
                    printf(" ");
                
            }
        }
        
    }    
}
