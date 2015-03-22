
//x=((M1'*M1*b1)+(M2'*M2*b2)+...(MK'*MK*bk))%m
//m=m1*m2*m3*...mk;
//Mi=m/mi;
//Mi' 为Mi的逆元
inline gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int ex_gcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;y=0;return a;
	}
	else{
		int d=ex_gcd(b,a%b,x,y);
		int t=x;
		x=y;
		y=t-(a/b)*y;
		return d;
	}
}
int China(int b[],int w[],int k){
	int d,x,y,a=0,m,n=1;
	for(int i=0;i<k;i++) n*=w[i];
	for(int i=0;i<k;i++){
		m=n/w[i];
		d=ex_gcd(w[i],m,x,y);
		a=(a+y*m*b[i])%n;
	}
	return a>0?a:a+n;
}

