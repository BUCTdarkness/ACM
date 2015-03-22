import java.util.*;
import java.math.*;
import java.io.*;
public class Main{
	public static void main(String[] args){
		Scanner cin=new Scanner(System.in);
		int ncase=0;
		long x,k;
		while(cin.hasNext()){
			x=cin.nextLong();k=cin.nextLong();
			if(x==0&&k==0) break;
			long tmp=x;
			for(long i=2;i<=k;i++){
				tmp-=tmp/i;
				if(tmp<i) break;
			}
			System.out.printf("Case #%d: ",++ncase);
			System.out.println(tmp*k);
		}
	}
}
