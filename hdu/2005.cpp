#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int d1[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int d2[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
bool judge(int year)
{
    if((year%4==0&&year%100!=0)||(year%400==0))
        return true;
    return false;
}
int main()
{
    int year,month,day;
    while(~scanf("%d/%d/%d",&year,&month,&day))
    {
        double s=0;
        if(judge(year))
        {
            for(int i=1;i<month;i++)
            {
                s+=d2[i];
            }
            s+=day;
        }
        else
        {
            for(int i=1;i<month;i++)
            {
                s+=d1[i];
            }
            s+=day;
        }
        cout<<s<<endl;
    }
    return 0;
}
