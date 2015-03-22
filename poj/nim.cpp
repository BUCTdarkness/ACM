bool nim(int x,int y){
	if(x==y) return true;
	if(x>y) swap(x,y);
	if(x==1&&y==2) return false;
	int n=1,h=1;
	set<int> a;a.add(2);
	while(x>n){while(!a.count(++n));h++;a.add(n+h);}
	return (x!=n||!a.count(y))?true:false;
}