#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
using namespace std;
struct Node{
	int x,y;
    bool operator < (const Node &rhs) const{
		return x==rhs.x?y<rhs.y:x<rhs.x;
	}
};
inline double dist(int x1,int y1,int x2,int y2){
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main(){
	int t;
	while(~scanf("%d",&t)){
		while(t--){
			int x1,x2,y1,y2;
			double val[10]={0};
			set<Node> g;
			vector<Node> q;
			for(int i=0;i<4;i++){
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				val[i]=dist(x1,y1,x2,y2);
				Node tmp;tmp.x=x1;tmp.y=y1;g.insert(tmp);
				tmp.x=x2;tmp.y=y2;g.insert(tmp);
				tmp.x=x2-x1;tmp.y=y2-y1;q.push_back(tmp);
			}
			bool flag=0;
			for(int i=0;i<q.size();i++){
				for(int j=i+1;j<q.size();j++){
					if(q[i].x*q[j].x+q[i].y*q[j].y==0){
						flag=1;break;
					}
				}
			}
		//	cout<<g.size()<<" "<<flag<<endl;
			if(!flag||g.size()!=4){
				printf("NO\n");continue;
			}
			if(val[0]==val[1]&&val[2]==val[3]){
				printf("YES\n");continue;
			}
			if(val[0]==val[2]&&val[1]==val[3]){
				printf("YES\n");continue;
			}
			if(val[0]==val[3]&&val[1]==val[2]){
				printf("YES\n");continue;
			}
			printf("NO\n");
		}
	}
	return 0;
}
