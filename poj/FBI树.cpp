#include<iostream>
using namespace std;
int n;
char a[1025];
int fbi(int i,int j)
{
    if(i<=j){
        int mid=(i+j)/2,I=0,B=0;
        if(i!=j){
        fbi(i,mid);
        fbi(mid+1,j);}
        while(i<=j)if(a[i++]=='0')B++;else I++;
        if(B>0 && I>0)cout<<'F';
        else if(B>0)cout<<'B';
        else cout<<'I';
        }
    return 0;
}
int main(void)
{
    cin>>n>>a;
    fbi(0,strlen(a)-1);
    return 0;
}
