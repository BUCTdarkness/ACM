import java.util.*;
import  java.math.*;

public class Main {
    public static BigInteger kgcd(BigInteger a,BigInteger b)throws Exception{
        BigInteger zero=new BigInteger("0");
    if(a.equals(zero)) return b;
    if(b.equals(zero)) return a;
    BigInteger x,y;
    x=a.and(BigInteger.valueOf(1));
    y=b.and(BigInteger.valueOf(1));
    if(!x.equals(zero)&&!y.equals(zero)){
      return kgcd(a.shiftRight(1), b.shiftRight(1)).shiftLeft(1);
    }
    else if(!y.equals(zero)){
      return kgcd(a, b.shiftRight(1));
    }
    else if(!x.equals(zero)){
      return kgcd(a.shiftRight(1), b);
    }
    else{
      BigInteger aa=a.subtract(b),bb=a.min(b);
      aa=aa.abs();
       return kgcd(aa,bb);
    }
  }
  public static void main(String [] args)throws Exception{
    Scanner cin=new Scanner(System.in);
        BigInteger one=new BigInteger("1");
        BigInteger zero=new BigInteger("0");
        BigInteger two= new BigInteger("2");
        BigInteger four= new BigInteger("4");
        BigInteger six = new BigInteger("6");
        BigInteger A;
        BigInteger B;
      int T;
      T=cin.nextInt();
      for(int tt=1;tt<=T;tt++){
        String a,b;
        a=cin.next();b=cin.next();
        A=new BigInteger(a,2);
        B=new BigInteger(b,2);
        BigInteger ans=A.gcd(B);
        System.out.print("Case #"+tt+": ");
        System.out.println(ans.toString(2));
      }
  }
}