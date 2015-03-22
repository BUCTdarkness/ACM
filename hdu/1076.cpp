#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
bool check(int y)
{
    if((y%4==0&&y%100!=0)||y%400==0)
        return true;
    else
        return false;
}
int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            int y,n;
            cin>>y>>n;
            while(true)
            {
                if(check(y))
                    break;
                y++;
            }
            for(int i=0;i<n-1;)
            {
                y+=4;
                if(check(y))
                    i++;
            }
            cout<<y<<endl;
        }
    }
    return 0;
}


