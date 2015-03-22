import java.util.*;
import java.io.*;
import java.math.*;
public class Main{
	public static void main(String[] args){
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext()){
			int t=cin.nextInt();
			for(int cas=1;cas<=t;cas++){
				int n=cin.nextInt();
				int ret;
				ret=(int)(Math.log10(Math.sqrt(2.0*Math.PI*n))+n*Math.log10(n/Math.E))+1;
				System.out.println(ret);
			}
		}
	}
}
