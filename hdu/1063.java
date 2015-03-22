import java.util.*;
import java.math.*;
import java.io.*;
public class Main{
	public static void main(String []args)throws Exception{
		Scanner cin=new Scanner(new InputStreamReader(System.in));
		PrintWriter cout=new PrintWriter(new OutputStreamWriter(System.out));
		while(cin.hasNext()){
			BigDecimal a=cin.nextBigDecimal();
			int b=cin.nextInt();
			String ans=a.pow(b).stripTrailingZeros().toPlainString();
			if(ans.startWith("0")) ans=ans.substring(1);
			cout.println(ans);
		}
	}
}
