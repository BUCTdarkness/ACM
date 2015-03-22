#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
typedef long long LL;
#define inf 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof a);
const int MAXN=1002,N=7;
int n,k,a[MAXN][MAXN],b[MAXN][MAXN],ret[MAXN][MAXN];

struct Matrix{  
    int a[N][N];  
    void init(){  
        memset(a,0,sizeof a);  
    }  
    void unit(){  
        memset(a,0,sizeof a);  
        for(int i=0;i<N;i++)  
            a[i][i]=1;  
    }  
};  
Matrix multiply(Matrix x,Matrix y){//矩阵乘  
    Matrix rst;  
    rst.init();  
    for(int i=0;i<N;i++){//新矩阵的[i][j]=x的第i行*y的第j列  
        for(int j=0;j<N;j++)  
            for(int k=0;k<N;k++){  
                rst.a[i][j]+=x.a[i][k]*y.a[k][j];  
                rst.a[i][j]%=6;  
            }  
    }  
    return rst;  
}  
Matrix _pow(Matrix a,int p){//快速幂  
    Matrix rst;  
    rst.unit();  
    while(p){  
        if(p&1)  
            rst=multiply(rst,a);  
        a=multiply(a,a);  
        p>>=1;  
    }  
    return rst;  
}  

void add(int &a,int b){
	a+=b;a%=6;
}
Matrix ba;
void solve(){
	ba.init();
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			for(int p=1;p<=n;p++)
				add(ba.a[i][j],b[i][p]*a[p][j]);
		}
	}
	ba=_pow(ba,n*n-1);//(BA)^(n-1)  [k,k]
	mem(ret,0);
	for(int i=1;i<=n;i++){//A*X  [n,k]
		for(int j=1;j<=k;j++){
			for(int p=1;p<=k;p++){
				add(ret[i][j],a[i][p]*ba.a[p][j]);
			}
		}
	}
	mem(a,0);
	for(int i=1;i<=n;i++){// X*B [n,n]
		for(int j=1;j<=n;j++){
			for(int p=1;p<=k;p++){
				add(a[i][j],ret[i][p]*b[p][j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans+=a[i][j];
			//printf("%d ",a[i][j]);
		}
		//printf("--\n");
	}
	printf("%d\n",ans);
}

int main(){
	while(cin>>n>>k&&n||k){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k;j++){
				scanf("%d",&a[i][j]);
				a[i][j]%=6;
			}
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++){
				scanf("%d",&b[i][j]);
				b[i][j]%=6;
			}
		solve();//(A*B)^n=A*((B*A)^n-1)*B
	}
	return 0;
}