import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.FileWriter;
class Main {
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String []args) throws Exception{
        int TC = Integer.parseInt(in.readLine());
        int T = 0;
        while (TC-- > 0) {
            T++;
            out.write("Case #" + T + ": ");
            BigInteger N = new BigInteger(in.readLine());
            BigInteger e = BigInteger.valueOf(8);
            BigInteger s = BigInteger.valueOf(7);
            BigInteger rlt = N.multiply(N).multiply(e).subtract(N.multiply(s)).add(BigInteger.ONE);
            out.write(rlt.toString());
            out.newLine();
        }
        out.flush();
    }
}