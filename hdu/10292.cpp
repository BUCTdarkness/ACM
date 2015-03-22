#include<iostream>
using namespace std;
int main()
{
    int n,i,count,c,num;
    while(cin>>n)
    {
       count=0;
       for(i=0;i<n;i++)
       {
           cin>>num;
           if(count==0)
           {
              c=num;
              count=1;
           }
           else
               {
                  if(c==num)
                      count++;
                  else
                      count--;
               }   
       }
       cout<<c<<endl;
    }
    return 0;
}
