#include<stdio.h>
#include<string.h>
int main()
{
    int i=0,j,t,length,consonant,vowel,f;
    char ch[2000][21];
    while(scanf("%s",ch[i])!=EOF&&strcmp(ch[i],"end")!=0)
    {
         length=strlen(ch[i]);
         t=1;
         f=0;
         vowel=0;
         consonant=0;
         for(j=0;j<length;j++)
         {
             if(ch[i][j]==ch[i][j+1])
                     if(ch[i][j]!='e'&&ch[i][j]!='o')
                        {
                           t=0;
                           break;
                        }
             if(ch[i][j]=='a'||ch[i][j]=='e'||ch[i][j]=='i'||ch[i][j]=='o'||ch[i][j]=='u')
             {
                 consonant=0;
                 vowel++;
                 f=1;
             }
             else
                 {
                     vowel=0;
                     consonant++;
                 }
             if(consonant==3||vowel==3)
                 {
                    t=0;
                    break;
                 }  
         }
         if(f==0)
                 t=0;
         printf("<%s>",ch[i]);
         if(t==1)
             printf(" is acceptable.\n");
         if(t==0)
             printf(" is not acceptable.\n");
         i++;  
    }
    return 0;
}
