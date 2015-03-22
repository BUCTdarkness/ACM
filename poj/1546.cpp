#include<stdio.h>

#include<stdlib.h>

#include<string.h>

int c[10];//6个F位2亿多，9位即可

char arr[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

int convert_ten(int a,char num[])

{

    int i,ans=0;

    int len=strlen(num);

    if(len>7)

    {

        printf("  ERROR\n");

        exit(0);

    }

    for(i=0;i<len;i++)

    {

        ans*=a;

        if(num[i]>='0'&&num[i]<='9')

            ans+=num[i]-'0';

        else

            ans+=num[i]-'A'+10;

    }

    return ans;

}

int convert_b(int temp,int b)

{

    int j=0,i;

    int temp0;

    memset(c,0,sizeof(c));

    if(0==temp)//不加该语句，输入0，无结果

    {

        c[0]=0;

        return 1;

    }

    else

    {

        while(temp)

        {

            c[j++]=temp%b;

            temp/=b;

        }

        /*

        没必要 

        for(i=0;i<j/2;i++)

        {

            temp0=c[i];

            c[i]=c[j-i-1];

            c[j-i-1]=temp0;

        }

        */

    }

    return j;

}

int main()

{

    char num[8];

    int a,b;

    int temp,len,k;

    while(~scanf("%s %d %d",num,&a,&b))

    {

        temp=convert_ten(a,num);

        len=convert_b(temp,b);

        if(len>7)

        {

            printf("  ERROR\n");

            continue;

        }

        else

        {

            for(k=0;k<7-len;k++)

                putchar(' ');

            for(k=len-1;k>=0;k--)

                    putchar(arr[c[k]]);

        }

        putchar('\n');

        //fflush(stdin);

        memset(num,0,sizeof(num));

    }

    return 0;

}
