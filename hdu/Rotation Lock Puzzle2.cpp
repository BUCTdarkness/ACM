#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=10;
const int maxm=32 + 10;

int n, M[maxn][maxn];
int d[maxn][maxm];      //d[i][j]��ʾ������������i�㣬�����Ͻǿ�ʼ���±��0��ʼ��˳ʱ���j����˭
int Max[maxn];      //Max[i]��ʾ��i��Խ��ߵ�4�����ĺ͵����ֵ
int r[maxn];        //r[i]��ʾ��i��ת���Խ��ߵ�4�����ĺ͵����ֵʱת�˶��ٴ�

void read()
{
    int i,j;
    for(i= 0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d", &M[i][j]);
}

void get_d()
{
    int i,j,m;
    for(i= 0; i<n/2; i++)
    {
        m=0;
        for(j=i; j<n-i; j++) d[i][m++]=M[i][j];
        for(j=i+1; j<n-i; j++) d[i][m++]=M[j][n-1-i];
        for(j=n-2-i; j>=i; j--) d[i][m++]=M[n-1-i][j];
        for(j=n-2-i; j>i; j--) d[i][m++]=M[j][i];
    }
}

void get_Mr()
{
    int i,j;
    for(i= 0; i<n/2; i++)
    {
        int N=(n - i*2) -1;
        int Ma=-1;
        for(j=0; j<N; j++)        //תj��
        {
            int temp=d[i][j] + d[i][j+N] + d[i][j+2*N] + d[i][j+3*N];
            if(temp>Ma)
            {
                Ma=temp;
                Max[i]=temp;
                r[i]=min(j, N-j);
            }
            else if(temp == Ma)
            {
                r[i]=min(r[i], j);
                r[i]=min(r[i], N-j);
            }
        }
    }
}

void solve()
{
    int sum_val=0, sum_rot=0,i;
    for(i= 0; i<n/2; i++) sum_val += Max[i];
    sum_val += M[n/2][n/2];
    for(i= 0; i<n/2; i++) sum_rot += r[i];
    printf("%d %d\n", sum_val, sum_rot);
}

int main()
{
    while(scanf("%d", &n) == 1 && n)
    {
        read();
        get_d();
        get_Mr();
        solve();
    }
    return 0;
}