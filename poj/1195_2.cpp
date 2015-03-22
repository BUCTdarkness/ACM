#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int MAX=1100;
int s;
void addx(int py,int px,int l,int r,int x,int v){
	tree[py][px]+=v;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(x<=mid) addx(py,(px<<1)+1,l,mid,x,v);
	else addx(py,(px<<1)+2,mid+1,r,x,v);
}
void addy(int py,int l,int r,int y,int x,int v){
	addx(py,0,1,s,x,v);
	if(l==r) return;
	int mid=(l+r)>>1;
	if(y<=mid) addy( (py<<1)+1,l,mid,y,x,v);
	else addy((py<<1)+2,mid+1,r,y,x,v);
}
int queryx(int py,int px,int l,int r,int x1,int x2){
	if(l==x1&&r==x2) return tree[py][px];
	int mid=(l+r)>>1;
	if(x2<=mid) return queryx(py,(px<<1)+1,l,mid,x1,x2);
	else if(x1>mid) return queryx(py,(px<<1)+2,mid+1,r,x1,x2);
	else{
		return queryx(py,(px<<1)+1,l,mid,x1,mid)+queryx(py,(px<<1)+2,mid+1,r,mid+1,x2);
	}
}
int queryy(int py,int l,int r,int y1,int y2,int x1,int x2){
	if(l==y1&&r==y2) return queryx(py,0,1,s,x1,x2);
	int mid=(l+r)>>1;
	if(y2<=mid) return queryy((py<<1)+1,l,mid ,y1,y2,x1,x2);
	if(y1>mid) return  queryy((py<<1)+2,mid+1,r ,y1,y2,x1,x2);
	else return queryy
}
