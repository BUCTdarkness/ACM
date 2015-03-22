#include<iostream>
#include<memory.h>
#include<string> 
#include<queue>
using namespace std;
int main()
{
    int t,n,m,i,j,I,U,M;
    string s;
    while(cin>>n)
    {
        while(n--)
        {
            cin>>s;
            I=0;
            U=0;
            M=0;
            if(s[0]!='M') 
            {
                cout<<"No"<<endl;
                continue;
            }    
            for(i=1;i<s.size();i++)
            {
            
                if(s[i]=='I')  I++;
                else if(s[i]=='U')  U++;
                else 
                {
                    M=1;
                    break;
                }    
            }
            if(M==1 || ((I+U)%2==1 && !(I==1 && U==0)) || I%3==0)
            {
                cout<<"No"<<endl;
            }
            else cout<<"Yes"<<endl;
        }            
    }
    return 0;    
}    