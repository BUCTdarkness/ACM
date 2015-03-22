class Solution{
public:
	vector<vector<int> > generateMatrix(int n){
		vector<int> tmp(n,0);
		vector<vector<int> >g(n,tmp);
		int lb=0,rb=n-1,ub=0,db=n-1;
		for(int i=1;i<=n*n;){
			for(int i1=lb;i1<=rb;i1++) g[ub][i1]=i++;
			if(i>n*n) return g;
			for(int i2=++ub;i2<=db;i2++) g[i2][rb]=i++;
			if(i>n*n) return g;
			for(int i3=--rb;i3>=lb;i3--) g[db][i3]=i++;
			if(i>n*n) return g;
			for(int i4=--db;i4>=ub;i4--) g[i4][lb]=i++;
			lb++;
		}
		return g;
	}
};

