//#pragma comment(linker, "/STACK:36777216")
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
#define MAXN 2000
#define MAXM 3000
#define LL long long
#define MOD 1000000007
using namespace std;
LL dpXor[1010][1024][2];  //dpXor[i][j]��ʾ�±���1~i����λ�����Ϊj���м�������� 0��ʾ������A[i],1��ʾ��������A[i]
LL dpAnd[1010][1024][2];  //dpAnd[i][j]��ʾ�±�>i����λ����Ϊj���м��������
int T,N,A[MAXN];
inline void check(LL &t){while(t>=MOD) t-=MOD;}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        memset(dpXor,0,sizeof(dpXor));
        memset(dpAnd,0,sizeof(dpAnd));
        for(int i=1;i<=N;i++)
            scanf("%d",&A[i]);
        for(int i=1;i<N;++i)
        {
            dpXor[i][A[i]][1]+=1;
            for(int j=0;j<1024;++j)
            {
                dpXor[i+1][j^A[i+1]][1]+=(dpXor[i][j][1]);
                dpXor[i+1][j^A[i+1]][1]+=(dpXor[i][j][0]);
                dpXor[i+1][j][0]+=(dpXor[i][j][1]);
                dpXor[i+1][j][0]+=(dpXor[i][j][0]);
                dpXor[i+1][j^A[i+1]][1]%=MOD;
				dpXor[i+1][j][0]%=MOD;
            }
        }
        for(int i=N;i>2;--i)
        {
            dpAnd[i][A[i]][1]+=1;
            for(int j=0;j<1024;++j)
            {
                dpAnd[i-1][j&A[i-1]][1]+=(dpAnd[i][j][1]);
                dpAnd[i-1][j&A[i-1]][1]+=(dpAnd[i][j][0]);
                dpAnd[i-1][j][0]+=(dpAnd[i][j][1]);
                dpAnd[i-1][j][0]+=(dpAnd[i][j][0]);
                dpAnd[i-1][j&A[i-1]][1]%=MOD;
				dpAnd[i-1][j][0]%=MOD;
            }
        }
        LL ans=0;
        for(int i=1;i<N;++i)
            for(int j=0;j<1024;++j)
                ans=(ans+dpXor[i][j][1]*(dpAnd[i+1][j][0]+dpAnd[i+1][j][1]))%MOD;
        printf("%I64d\n",ans);
    }
    return 0;
}
