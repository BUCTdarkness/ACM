#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
double jinwei(string a)
{
    int len=a.size();
    double h=0;
    if(a[len-2]=='c')
    {
        h=10;
    }
    else if(a[len-2]=='d')
    {
        h=100;
    }
    else if(a[len-2]=='u')
    {
        h=0.001;
    }
    else if(a[len-2]=='n')
    {
        h=0.000001;
    }
    else if(a[len-2]=='m'||a[len-2]=='p')
    {
        h=1;
    }
    else
    {
        h=1000;
    }
    return h;
}
double change(string a)
{

    char s[1010];
    int k=0;
    double h=jinwei(a);
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='a'&&a[i]<='z')
            break;
        s[k++]=a[i];
    }
    s[k]='\0';
    double sum=0;
    sum=atof(s);
    sum*=h;
    return sum;
}

int main()
{
    int t;
    while(cin>>t)
    {
        for(int k=1;k<=t;k++)
        {
            string a,b,c;
            cin>>a>>b>>c;
            double v1,v2,v3;
            v1=change(a);
            v2=change(b);
            v3=change(c);
          //  cout<<v1<<" "<<v2<<" "<<v3<<endl;
            double sum=v3*v1/v2;
            int s=sum*100+0.5;
            cout<<"Case "<<k<<": ";
            printf("%.2lfpx\n",(double)s/100);
        }
    }
    return 0;
}

