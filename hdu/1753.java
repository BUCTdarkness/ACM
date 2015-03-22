import java.util.*;
import java.math.*;
import java.io.*;
public class Main{
	public static void main(String []args)throws Exception{
		Scanner cin=new Scanner(new InputStreamReader(System.in));
		PrintWriter cout=new PrintWriter(new OutputStreamWriter(System.out));
		while(cin.hasNext()){
			BigDecimal a,b;
			a=cin.nextBigDecimal();
			b=cin.nextBigDecimal();
			a=a.add(b).stripTrailingZeros().toPlainString();
			cout.println(a);
		}
	}
}

