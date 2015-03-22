
import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        BigInteger one=new BigInteger("1");
        BigInteger zero=new BigInteger("0");
        BigInteger two= new BigInteger("2");
        BigInteger four= new BigInteger("4");
        BigInteger six = new BigInteger("6");
        BigInteger []a=new BigInteger[3010];
        while(input.hasNext()){
            int n,t;
            t=input.nextInt();
            while(t!=0){
                t--;
                n=input.nextInt();
                int []p=new int[3010];
                for(int i=0;i<n;i++){
                    p[i]=input.nextInt();
                }
                a[0]=one;
                int flag=1;
                for(int i=1;i<n;i++){
                    a[i]=a[i-1];
                    a[i]=a[i].multiply(BigInteger.valueOf(n-i));
                    a[i]=a[i].divide(BigInteger.valueOf(i));
                }
                if(n%2==1){
                    flag=1;
                }
                else{
                    flag=-1;
                }
                BigInteger ret = zero;
                for(int i=0;i<n;i++){
                    BigInteger tt=a[i];
                    tt=tt.multiply(BigInteger.valueOf(flag));
                    tt=tt.multiply(BigInteger.valueOf(p[i]));
                    ret=ret.add(tt);
                    flag*=-1;
                }
                System.out.println(ret);
            }
        }
    }
}
