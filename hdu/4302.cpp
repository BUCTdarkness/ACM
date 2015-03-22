#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
multiset<int>cake;
multiset<int>::iterator p1;
multiset<int>::iterator p2;
int dir=0;
int main(){
	int T,L,n,kase=0;
	scanf("%d",&T);
	while(T--){
		int op,pos,posation=0,cnt=0;
		long long sum=0;
		cake.clear();
		dir=1;
		scanf("%d%d",&L,&n);
	    for(int i=0;i<n;i++){
	    	scanf("%d",&op);
	    	if(op==0){
	    		scanf("%d",&pos);
	    		cake.insert(pos);
	    		cnt++;
	    	}
	    	else{
                if(cnt==0)    continue;
	    		p1=cake.lower_bound(posation);
	    		if(p1==cake.end()){
                    p1--;
                    sum+=(posation-(*p1));
                    posation=*p1;
                    dir=0;
                    cnt--;
                    cake.erase(p1);
                    continue;
	    		}
	    		if(p1==cake.begin()){
                    sum+=((*p1)-posation);
                    if(*p1!=posation)
                        dir=1;
                    posation=*p1;
                    cnt--;
                    cake.erase(p1);
                    continue;
	    		}
	    		if(*p1==posation){
                    cnt--;
                    cake.erase(p1);
                    continue;
	    		}
	    		p2=p1;
	    		p2--;
	    		int dis1=posation-(*p2),dis2=(*p1)-posation;
	    		if(dis1==dis2){
                    sum+=dis1;
                    cnt--;
                    if(dir==0){
                        posation=(*p2);
                        cake.erase(p2);
                    }
                    else{
                        posation=(*p1);
                        cake.erase(p1);
                    }
                    continue;
	    		}
	    		else if(dis1>dis2){
                    dir=1;
                    sum+=dis2;
                    cnt--;
                    posation=(*p1);
                    cake.erase(p1);
	    		}
	    		else{
                    dir=0;
                    sum+=dis1;
                    cnt--;
                    posation=(*p2);
                    cake.erase(p2);
	    		}
	    	}
	    }
	    cout<<"Case "<<++kase<<": "<<sum<<endl;
	}
}