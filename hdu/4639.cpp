#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
const int MAX=10090;
int s[MAX],f[MAX];
int main()
{
    int T;
    f[1]=1;
    f[2]=2;
    for(int i=3;i<=10087;i++)
        f[i]=(f[i-1]+f[i-2])%10007;
    while(cin>>T)
    {
        for(int kase=1;kase<=T;kase++)
        {
            string sentence;
            cin>>sentence;
            int cnt=0,k=0;
            for(int i=1;i<sentence.size();i++)
            {
                if(sentence[i]=='e'&&sentence[i-1]=='h')
                {
                    if(cnt==0)
                    {
                        k++;
                    }
                    cnt++;
                    s[k]=cnt;
                    i++;
                }
                else
                {
                    cnt=0;
                }
            }
            int sum=1;
            for(int i=1;i<=k;i++)
            {
                sum=(f[s[i]]*sum)%10007;
            }
            cout<<"Case "<<kase<<": "<<sum<<endl;
        }
    }
    return 0;
}
