#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> g;
void change(int n)
{
    g.clear();
    while(n)
    {
        g.push_back(n%2);
        n/=2;
    }
    for(int i=g.size()-1;i>=0;i--)
    {
        cout<<g[i];
    }
    cout<<endl;
}
int main()
{
    int n;
    while(cin>>n)
    {
        change(n);
    }
    return 0;
}
