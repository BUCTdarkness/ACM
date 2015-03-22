#include<iostream>
using namespace std;
int main()
{
 int store[2001],A,B,n,i,k = 0;
 int a[201];
 while(cin>>A>>B>>n)
 {
  int j = 2;
  if(A == 0 && B == 0 && n == 0) break;
  a[0] = 1;
  a[1] = 1;
  for(i = 2;i < 50 ; i++)
  {
   a[i] = (A*a[i-1]+B*a[i-2])%7;
   if(a[i] == a[2] && a[i-1] == 1 && a[i-2] == 1 && i > 4) break;
  }
  n = n % (i-2);
  if(n == 0) cout<<a[i-3]<<endl;
  else
  {
   n--;
   cout<<a[n]<<endl;
  }
 }
 return 0;
}
