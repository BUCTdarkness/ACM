#include<stdio.h>
#include<string.h>
int main()
{
    char ch[100];
    int n,a,b,c,d,i,j,length,sum;
    bool flag;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            a=b=c=d=sum=0;
            flag=true;
            scanf("%s",ch);
            length=strlen(ch);
            if(length<8||length>16)
            {
                flag=false;
            }
            if(flag){
            for(j=0;j<length;j++)
            {
                if(ch[j]>='A'&&ch[j]<='Z')
                    a=1;
                else
                        if(ch[j]>='a'&&ch[j]<='z')
                           b=1;
                        else 
                             if(ch[j]>='0'&&ch[j]<='9')
                                c=1;
                             else 
                                  if(ch[j]=='~'||ch[j]=='!'||ch[j]=='@'||ch[j]=='#'||ch[j]=='$'||ch[j]=='%'||ch[j]=='^')
                                      d=1;
            } 
            }
            sum=a+b+c+d        ;
            if(sum<3)
                flag=false;
            if(flag) 
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
