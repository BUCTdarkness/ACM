import java.util.*;
import java.math.*;
import java.io.*;
public class Main{
	public static void main(String []args){
		Scanner cin=new Scanner(new InputStream(System.in));
		PrintWriter cout=new PrintWriter(new OutputStreamWriter(System.out));
		while(cin.hasNext()){
			int n=cin.nextInt();
			BigInteger ans=new BigInteger(BigInteger.valueOf(1));
			for(int i=2;i<=n;i++){
				ans=ans.multiply(BigInteger.valueOf(i));
			}
			cout.println(ans.toString());
			cout.flush();cout.close();
		}
	}
}
