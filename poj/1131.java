import java.util.*;
import java.math.*;
import java.io.*;

public class Main(){
	public static void main(String[] args){
		Scanner cin=new Scanner(System.in);
		BigDecimal zero=new BigDecimal(0);
		BigDecimal one=new BigDecimal(1),eight=new BigDecimal(8);
		while(cin.hasNext()){
			String str;
			BigDecimal ans=new BigDecimal(0);
			BigDecimal a=one.divide(eight);
			str=cin.next();
			for(int i=2;i<str.size();i++){
				ans=ans.add(a.multiply(new BigDecimal(str[i]-48)));
				a=a.divide(eight);
			}
			System.out.println(str+"[8]"+"="+ans.toString()+"[10]");
		}
	}
}