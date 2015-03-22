#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
const int MAX=2010;
vector<int>G[MAX];
map<string,int> mp;
map<int,string> ms;
int cnt[MAX];
bool vis[MAX];
int N,Q,pos;
void init()
{
    mp.clear();
    ms.clear();
    for(int i=0;i<MAX;i++)
    {
        G[i].clear();
    }
}
void bfs(int s)
{
    for(int i=0;i<G[s].size();i++)
    {
        int v=G[s][i];
        vis[v]=true;
    }
    for(int i=0;i<G[s].size();i++)
    {
        int u=G[s][i];
        for(int j=0;j<G[u].size();j++)
        {
            int v=G[u][j];
            if(v==s||vis[v]==true)
                continue;
            cnt[v]++;
        }
    }
    int m=-1;
    for(int i=0;i<pos;i++)
        m=max(m,cnt[i]);
    if(m==0)
        cout<<"-"<<endl;
    else
    {
        vector<string> v;
        for(int i=0;i<pos;i++)
        {
            if(cnt[i]==m)
            {
                v.push_back(ms[i]);;
            }
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            if(i!=0)
                cout<<" ";
            cout<<v[i];
        }
        cout<<endl;
    }
}
int main()
{
    int T;
    while(cin>>T)
    {
        for(int kase=1;kase<=T;kase++)
        {
            cin>>N>>Q;
            init();
            pos=0;
            for(int i=1;i<=N;i++)
            {
                string s1,s2;
                cin>>s1>>s2;
                getchar();
                if(mp[s1]==0)
                {
                    mp[s1]=pos;
                    ms[pos++]=s1;
                }
                if(mp[s2]==0)
                {
                    mp[s2]=pos;
                    ms[pos++]=s2;
                }
               // cout<<"a"<<mp[s1]<<" "<<mp[s2]<<endl;
                G[mp[s1]].push_back(mp[s2]);
                G[mp[s2]].push_back(mp[s1]);
            }
            for(int q=1;q<=Q;q++)
            {

                memset(cnt,0,sizeof(cnt));
                memset(vis,false,sizeof(vis));
                string s;
                cin>>s;
                int v=mp[s];
                bfs(v);
            }
        }
    }
    return 0;
}

