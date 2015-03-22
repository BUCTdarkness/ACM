import java.util.*;
import java.math.*;
public class Main{
	public static void main(String [] args){
		Scanner i=new Scanner(System.in);
		for(;i.hasNext();){
			BigDecimal k=i.nextBigDecimal().pow(i.nextInt());
			System.out.println(k.toPlainString().replaceAll("^0*|[.]?0*$","" ) ) ;
		}
	}
}
