import java.util.*;
import java.math.*;
import java.io.*;
public class Main{
	public static long extgcd(int a,int b,long []x,long []y){
		if(b==0){x[0]=1;y[0]=0;return a;}
		long d=extgcd(b,a%b,x,y);
		long t=x[0];x[0]=y[0];y[0]=t-a/b*y[0];
		return d;
	}
	public static long mod(long a,long b){return a%b+(a%b>0?0:b);}
	public static long China_Rest(int n,int []a,int []b){
		if(n==1&&a[0]==0) return b[0];
		long ans=a[0],lcm=b[0];
		boolean legal=true;
		for(int i=1;i<n;i++){
			long gcd;
			long []x=new long[2];
			long []y=new long[2];
			gcd=extgcd(lcm,b[i],x,y);
			if((a[i]-ans)%gcd){legal=false;break;}
			long tmp=lcm*mod((a[i]-ans)/gcd*x[0],b[i]/gcd);
			lcm=lcm/gcd*b[i];
			ans=mod(ans+tmp,lcm);
		}
		return legal?ans:-1;
	}
	public static void main(){

	}
}
