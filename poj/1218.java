import java.util.*;
import java.math.*;
import java.io.*;
public class Main{
	public static void main(String[] args){
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext()){
			int T=cin.nextInt();
			while(T--){
				int n=cin.nextInt();
				int []a=new int[110];
				for(int i=1;i<=n;i++) a[i]=0;
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(j%i==0){
							a[j]=~a[j];
						}
					}
				}
				int ret=0;
				for(int i=1;i<=n;i++){
					if(a[i]!=0) ret++;
				}
				System.out.println(ret);
			}
		}
	}
}
