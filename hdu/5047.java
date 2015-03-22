import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class Main
{
    public static void main(String args[]) throws Exception
    {
        //Scanner cin=new Scanner(System.in);
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        PrintWriter cout=new PrintWriter(System.out,true);
        
        int T=cin.nextInt();
        
        //BigInteger ans, temp;
        
        for (int TT=1;TT<=T;TT++)
        {
            long n=cin.nextLong();
            //cout.print("Case #"+TT+": ");
            //System.out.print("Case #"+TT+": ");
            //ans=BigInteger.valueOf((n-1)*8+4);
            //temp=BigInteger.valueOf(n);
            //ans=ans.multiply(BigInteger.valueOf(n));
            //temp=BigInteger.valueOf(n*3-1);
            //ans=ans.subtract(temp);
            //System.out.println(ans.toString());
            cout.println("Case #"+TT+": "+BigInteger.valueOf((n-1)*8+4).multiply(BigInteger.valueOf(n)).subtract(BigInteger.valueOf(n*3-1)).toString());
            cout.flush();
        }
    }
}