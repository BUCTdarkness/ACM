import java.math.BigInteger;
import java.util.*;
import java.io.*;

class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1000];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    private int read() {
        if (numChars == -1)
            throw new UnknownError();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new UnknownError();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int readInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9') throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public int[] readIntArray(int length) {
        int[] res = new int[length];
        for (int i = 0; i < length; i ++) res[i] = readInt();
        return res;
    }

    public int[][] readIntArray(int n, int m) {
        int[][] res = new int[n][m];
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                res[i][j] = readInt();
        return res;
    }

    public long readLong() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9') throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public long[] readLongArray(int length) {
        long[] res = new long[length];
        for (int i = 0; i < length; i ++) res[i] = readLong();
        return res;
    }

    public long[][] readLongArray(int n, int m) {
        long[][] res = new long[n][m];
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                res[i][j] = readLong();
        return res;
    }

    public String readString() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuffer res = new StringBuffer();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public String[] readStringArray(int length) {
        String[] res = new String[length];
        for (int i = 0; i < length; i ++) res[i] = readString();
        return res;
    }

    public String next() {
        return readString();
    }

    private String readLine0() {
        StringBuffer buf = new StringBuffer();
        int c = read();
        while (c != '\n' && c != -1) {
            buf.appendCodePoint(c);
            c = read();
        }
        return buf.toString();
    }

    public String readLine() {
        String s = readLine0();
        while (s.trim().length() == 0)
            s = readLine0();
        return s;
    }

    public String readLine(boolean ignoreEmptyLines) {
        if (ignoreEmptyLines)
            return readLine();
        else
            return readLine0();
    }

    public BigInteger readBigInteger() {
        try {
            return new BigInteger(readString());
        } catch (NumberFormatException e) {
            throw new InputMismatchException();
        }
    }

    public char readCharacter() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        return (char) c;
    }

    public char[] readCharArray(int length) {
        char[] res = new char[length];
        for (int i = 0; i < length; i ++)
            res[i] = readCharacter();
        return res;
    }

    public char[][] readCharArray(int n, int m) {
        char[][] res = new char[n][m];
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                res[i][j] = readCharacter();
        return res;
    }

    public double readDouble() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!isSpaceChar(c) && c != '.') {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        }
        if (c == '.') {
            c = read();
            double m = 1;
            while (!isSpaceChar(c)) {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                m /= 10;
                res += (c - '0') * m;
                c = read();
            }
        }
        return res * sgn;
    }

    public double[] readDoubleArray(int length) {
        double[] res = new double[length];
        for (int i = 0; i < length; i ++) res[i] = readDouble();
        return res;
    }

    public double[][] readDoubleArray(int n, int m) {
        double[][] res = new double[n][m];
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                res[i][j] = readDouble();
        return res;
    }

    private boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(Object...objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }

    public void printDouble(double x, int precision) {
        writer.printf("%." + precision + "f", x);
    }

    public void printLineDouble(double x, int precision) {
        printDouble(x, precision);
        printLine();
    }

    public void printLine(Object...objects) {
        print(objects);
        writer.println();
    }

    public void printIntArray(int[] data) {
        for (int i = 0; i < data.length; i ++)
            if (i < data.length - 1) {
                print(data[i] + " ");
            } else {
                print(data[i]);
            }
    }

    public void printLongArray(long[] data) {
        for (int i = 0; i < data.length; i ++)
            if (i < data.length - 1) {
                print(data[i] + " ");
            } else {
                print(data[i]);
            }
    }

    public void close() {
        writer.close();
    }
}

public class Main {
    public static void main(String[] args) {
        InputReader s = new InputReader(System.in);
        OutputWriter out = new OutputWriter(System.out);
        int T = s.readInt();
        for (int caseNo = 0; caseNo < T; caseNo ++) {
            BigInteger n = s.readBigInteger();
            BigInteger ans = BigInteger.valueOf(8).multiply(n).multiply(n.subtract(BigInteger.ONE));
            ans = ans.add(n);
            ans = ans.add(BigInteger.ONE);
            out.printLine("Case #" + (caseNo + 1) + ": " + ans);
        }
        out.close();
    }
}