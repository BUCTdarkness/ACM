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
#define PI 3.1415926535898
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
#define mat_size 3
using namespace std;
int N;
double X[50],Y[50],Z[50];
struct Mat{
    double V[mat_size][mat_size];
    void Init(){
        for(int i=0;i<mat_size;i++)
            for(int j=0;j<mat_size;j++)
                V[i][j]=0;
    }
    void mat_initial_eye()    {
        for(int i=0;i<mat_size;i++)
            for(int j=0;j<mat_size;j++)
                V[i][j]=0;
        for (int i = 0; i < mat_size; ++i){
            V[i][i]=1;
        }
    }
};
Mat mulit(Mat a,Mat b){
    Mat ret;
    ret.Init();
    int i,j,k;
    for (i = 0; i < mat_size; ++i){
        for ( j = 0; j < mat_size; ++j){
            for( k = 0; k < mat_size; ++k)
                ret.V[i][j]=(ret.V[i][j]+a.V[i][k]*b.V[k][j]);
        }
    }
    return ret;
}
int main(){
    #ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
    #endif
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%lf%lf%lf",&X[i],&Y[i],&Z[i]);
        }
        Mat Ans;
        Ans.Init();
        Ans.mat_initial_eye();

        for(int i=0;i<N;i++){
            Mat T;
            T.Init();
            double cosz=cos(Z[i]),sinz=sin(Z[i]);
            T.V[0][0]=cosz ;T.V[0][1]=sinz;T.V[0][2]=0;
            T.V[1][0]=-sinz;T.V[1][1]=cosz;T.V[1][2]=0;
            T.V[2][0]=X[i]-X[i]*cosz+Y[i]*sinz;T.V[2][1]=Y[i]-X[i]*sinz-Y[i]*cosz;T.V[2][2]=1;
            Ans=mulit(Ans,T);
        }
        if(Ans.V[0][0]>1)    Ans.V[0][0]=1;
        if(Ans.V[0][0]<-1)   Ans.V[0][0]=-1;

        double p=acos(Ans.V[0][0]);
        Mat T1;
        T1.Init();
        double cosp=cos(p),sinp=sin(p);
        T1.V[0][0]=cosp ;T1.V[0][1]=sinp;T1.V[0][2]=0;
        T1.V[1][0]=-sinp;T1.V[1][1]=cosp;T1.V[1][2]=0;
        if(!(fabs(T1.V[0][0]-Ans.V[0][0])<eps && fabs(T1.V[0][1]-Ans.V[0][1])<eps && fabs(T1.V[1][0]-Ans.V[1][0])<eps && fabs(T1.V[1][1]-Ans.V[1][1])<eps))
            p=2*PI-p;
        double a=Ans.V[0][0],b=Ans.V[0][1];
        double k1=Ans.V[2][0],k2=Ans.V[2][1];
        double d=(1-a)*(1-a)+b*b;
        double d1=(k1*(1-a)-k2*(b));
        double d2=(k2*(1-a)+k1*(b));
        double ansx=d1/d,ansy=d2/d;
        printf("%.10lf %.10lf %.10lf\n",ansx,ansy,p);
    }
    return 0;
}
