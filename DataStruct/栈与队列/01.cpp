#include "iostream"
using namespace std;
int m,n,sum=0,result=0,min_result=0;
int a[10][10];
 void dfs(int row, int col,int tempsum,int step,int i,int j)
{
if(tempsum==sum/2)
{ if(i==0 && j==0)
{ 
result=step;

}
else 
result = m*n-step;
if(min_result > result || !min_result)
min_result =result;
return ;
}
else if(row < m && col <n)
{
dfs(row+1,col,tempsum+a[row+1][col],step+1,i,j);
dfs(row, col+1,tempsum+a[row][col+1],step+1,i,j);
} }
int main()
{ cin >> n >> m;
for(int i=0 ; i<m ; i++)
for(int j=0 ; j<n ;j++)
{
cin >> a[i][j];
sum+=a[i][j];
}

if(sum%2)
{
cout << 0;
return 0;
}
for(i=0 ; i<m ; i++)
for(int j=0 ; j<n ;j++)
{
dfs(i,j,a[i][j],1,i,j);

}
if(result)
cout <<min_result << endl; return 0;
}