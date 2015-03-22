import java.util.*;
import java.io.*;
import java.math.*;
public class Main{
	public static int solve(int n){
		int cnt=1;
		while(n!=1){
			if(n%2!=0) n=3*n+1;
			else n=n/2;
			cnt++;
		}
		return cnt;
	}
	public static void main(String[] args){
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext()){
			int a,b,x,y;
			a=cin.nextInt();b=cin.nextInt();
			x=Math.min(a,b);y=Math.max(a,b);
			int ret=0;
			for(int i=x;i<=y;i++){
				int tmp=solve(i);
				if(ret<tmp) ret=tmp;
			}
			System.out.println(a+" "+b+" "+ret);
		}
	}
}