import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class 1207{
	public int solve(int i){
		int cnt=0;
		while(i!=1){
			if(n&1) n=3*n+1;
			else n=n/2;
			cnt++;
		}
		return cnt;
	}
	public static void main(){
		Scanner cin=new Scanner(System.in);
		while(input.hasNext()){
			int x,y;
			x=cin.nextInt();y=cin.nextInt();
			int ret=-1;
			for(int i=x;i<=y;i++){
				int tmp=solve(i);
				if(ret<tmp) ret=tmp;
			}
			System.out.println(ret);
		}
	}
}