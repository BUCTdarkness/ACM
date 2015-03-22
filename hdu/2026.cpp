#include<stdio.h>
#include<string.h>
int main()
{
    char ch[1000];
    int len,i;
    while(gets(ch))
    {
        len=strlen(ch);
        for(i=0;i<len;i++)
        {
            if(i==0)
                ch[i]-=32;
            else
                {
                    if(ch[i]==' '&&i<len-1)
                        ch[i+1]-=32;
                }
        }
        puts(ch);
    }
    return 0;
}
