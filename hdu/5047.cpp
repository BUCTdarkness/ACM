//#pragma comment(linker, "/STACK:36777216")
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;

namespace FFT
{
    #define MULT_REAL(a, b, c, d) ((a)*(c) - (b)*(d))
    #define MULT_IMAG(a, b, c, d) ((a)*(d) + (b)*(c))
    #define FFT_DIGITS 4
    const double Pi = acos(-1.0);

    int cap = 1;
    double *Real[2] = {new double[cap], new double[cap]};
    double *Imag[2] = {new double[cap], new double[cap]};
    double *w[2] = {new double[cap], new double[cap]};
    int *rev = new int[cap];

    void fft(double *real, double *imag, int n)
    {
        int logn = 0, i;
        while((1 << logn) < n)
            logn++;
        rev[0] = 0;
        for(int i = 1; i < (1 << logn); i++)
            rev[i] = rev[i / 2] / 2 + (  (i & 1) << (logn - 1)  );

        for(i = 0; i < n; i++)
        {
            w[0][i] = cos(2 * Pi * i / n);
            w[1][i] = sin(2 * Pi * i / n);
        }
        for(i = 0; i < n; i++)
        {
            if (i < rev[i])
            {
                std::swap(real[i], real[rev[i]]);
                std::swap(imag[i], imag[rev[i]]);
            }
        }

        for(int k = 2; k <= n; k *= 2)
        {
            int shift = k / 2;
            int blocks = n / k;
            for(int block = 0; block < n; block += k)
            {
                int idx = block * blocks % n;
                double *re = real + block;
                double *im = imag + block;
                double *re_end = re + shift;
                double *im_end = im + shift;
                double *re_next = re_end;
                double *im_next = im_end;
                double *w0_ptr = w[0] + idx;
                double *w1_ptr = w[1] + idx;
                double *w0_end = w[0] + n;
                for(; re != re_end; re++, re_next++, im++, im_next++)
                {
                    double uR = *re, uI = *im;
                    double vR = MULT_REAL(*w0_ptr, *w1_ptr, *re_next, *im_next);
                    double vI = MULT_IMAG(*w0_ptr, *w1_ptr, *re_next, *im_next);
                    *re = uR + vR;
                    *im = uI + vI;
                    *re_next = uR - vR;
                    *im_next = uI - vI;
                    idx += blocks;
                    w0_ptr += blocks;
                    w1_ptr += blocks;
                    if (w0_ptr >= w0_end)
                    {
                        w0_ptr -= n;
                        w1_ptr -= n;
                    }
                }
            }
        }
    }

    void invert_fft(double *real, double *imag, int n)
    {
        fft(real, imag, n);
        for(int i = 0; i < n; i++)
        {
            real[i] /= n;
            imag[i] /= n;
        }
        std::reverse(real + 1, real + n);
        std::reverse(imag + 1, imag + n);
    }

    int parseInt(const char *a, int len)
    {
        int res = 0;
        for(int i = 0; i < len; i++)
            res = res * 10 + a[i] - '0';
        return res;
    }

    void getDtf(double *Real, double *Imag, const char *a, int len, int n)
    {
        int i, pos;
        for(i = len - FFT_DIGITS, pos = 0; i >= 0; i -= FFT_DIGITS, pos++)
        {
            Real[pos] = parseInt(a + i, FFT_DIGITS);
            Imag[pos] = 0;
        }
        if (i + FFT_DIGITS != 0)
        {
            Real[pos] = parseInt(a, i + FFT_DIGITS);
            Imag[pos] = 0;
            pos++;
        }
        std::fill(Real + pos, Real + n, 0.0);
        std::fill(Imag + pos, Imag + n, 0.0);
        fft(Real, Imag, n);
    }

    std::string multiply_solve(const char *str1, int len1, const char *str2, int len2, bool negative)
    {
        int i;
        int n = std::max((len1 + FFT_DIGITS - 1) / FFT_DIGITS, (len2 + FFT_DIGITS - 1) / FFT_DIGITS);
        while(n & (n - 1))
            n++;
        n *= 2;
        if (cap < n)
        {
            cap = n * 2;
            for(i = 0; i < 2; i++)
            {
                Real[i] = (double*)realloc(Real[i], cap * sizeof(double));
                Imag[i] = (double*)realloc(Imag[i], cap * sizeof(double));
                w[i] = (double*)realloc(w[i], cap * sizeof(double));
            }
            rev = (int*)realloc(rev, cap * sizeof(int));
        }
        int pow10 = 1;
        for(i = 0; i < FFT_DIGITS; i++)
            pow10 *= 10;
        getDtf(Real[0], Imag[0], str1, len1, n);
        getDtf(Real[1], Imag[1], str2, len2, n);
        for(i = 0; i < n; i++)
        {
            double re = MULT_REAL(Real[0][i], Imag[0][i], Real[1][i], Imag[1][i]);
            double im = MULT_IMAG(Real[0][i], Imag[0][i], Real[1][i], Imag[1][i]);
            Real[0][i] = re;
            Imag[0][i] = im;
        }
        invert_fft(Real[0], Imag[0], n);
        std::vector<long long> res(n);
        for(i = 0; i < n; i++)
            res[i] = Real[0][i] + 0.5; // ?и║eио???икии?

        for(i = 0; i < n - 1; i++)
        {
            res[i + 1] += res[i] / pow10;
            res[i] %= pow10;
        }
        for(i = n - 1; i > 0 && res[i] == 0; i--);

        char fmt[] = "%0*d";
        char buf[20];
        fmt[2] = FFT_DIGITS + '0';
        std::string result;
        if (!(i == 0 && res[0] == 0))
            if (negative)
                result += "-";
        sprintf(buf, "%d", (int)res[i--]);
        result += buf;
        for( ; i >= 0; i--)
        {
            sprintf(buf, fmt, (int)res[i]);
            result += buf;
        }
        return result;
    }
}
class BigInteger
{
    int *a;
    int size;
    int capacity;
    bool minus;

    static const int BASE;
    static const int BASE_FFT_DIGITS;

    void reduce() {
        while(size > 1 && a[size - 1] == 0)
            size--;
        if (isZero())
            minus = false;
    }

    void alloc(int amount) {
        capacity = amount * 2;
        a = new int[capacity];
    }

    void ensureCapacity(int amount) {
        if (amount > capacity) {
            capacity = amount * 2;
            a = (int*)realloc(a, capacity * sizeof(int));
        }
    }

public:

    bool isZero() const {
        return size == 1 && a[0] == 0;
    }

    int getSign() const {
        if (isZero())
            return 0;
        return minus ? -1 : 1;
    }

    BigInteger abs() const {
        return minus ? -*this : *this;
    }

    BigInteger() {
        this->alloc(1);
        size = 1;
        a[0] = 0;
    }

    explicit BigInteger(const std::string& s) {
        this->alloc(s.size() / BASE_FFT_DIGITS + 1);
        size = 0;
        minus = s[0] == '-';
        int lf = int(minus);
        if (s[0] == '+')
            lf = 1;

        for(int i = (int)s.size() - 1; i >= lf; i -= BASE_FFT_DIGITS) {
            int digit = 0;
            for(int j = std::max(lf, i - BASE_FFT_DIGITS + 1); j <= i; j++)
                digit = digit * 10 + s[j] - '0';
            a[size++] = digit;
        }
        reduce();
    }

    explicit BigInteger(long long x) {
        this->alloc(3);
        a[0] = 0;
        minus = false;
        if (x < 0) {
            minus = true;
            x = -x;
        }
        int i;
        for(i = 0; x != 0; i++) {
            a[i] = int(x % BASE);
            x /= BASE;
        }
        size = std::max(1, i);
        reduce();
    }

    BigInteger(const BigInteger &p) {
        this->alloc(p.size);
        size = p.size;
        minus = p.minus;
        memcpy(a, p.a, size * sizeof(int));
    }

    BigInteger &operator =(const BigInteger &p) {
        ensureCapacity(p.size);
        size = p.size;
        minus = p.minus;
        memcpy(a, p.a, size * sizeof(int));
        return *this;
    }

    std::string toString() const {
        char buf[20];
        sprintf(buf, "%d", a[size - 1]);
        std::string res(buf);
        char fmt[] = "%0*d";
        fmt[2] = BASE_FFT_DIGITS + '0';
        for(int i = size - 2; i >= 0; i--) {
            sprintf(buf, fmt, a[i]);
            res += buf;
        }
        if (minus)
            res = "-" + res;
        return res;
    }

    long long toLongLong() const {
        long long res = 0;
        for(int i = size - 1; i >= 0; i--)
            res = res * BASE + a[i];
        return minus ? -res : res;
    }

    BigInteger operator-() const {
        BigInteger res(*this);
        res.minus ^= true;
        res.reduce();
        return res;
    }

    void operator +=(const BigInteger& p) {
        if (p.isZero())
            return;
        if (isZero()) {
            *this = p;
            return;
        }
        if (minus != p.minus) {
            *this -= -p;
            return;
        }
        int i;
        int carry = 0;
        ensureCapacity(std::max(size, p.size) + 1);
        for(i = 0; i < p.size || carry != 0; i++) {
            carry += (i < size ? a[i] : 0) + (i < p.size ? p.a[i] : 0);
            int ncarry = 0;
            while (carry >= BASE) {
                carry -= BASE;
                ncarry++;
            }
            a[i] = carry;
            carry = ncarry;
        }
        size = std::max(size, i);
        reduce();
    }

    void operator -=(const BigInteger& p) {
        if (p.isZero())
            return;
        if (isZero()) {
            *this = -p;
            return;
        }
        if (minus != p.minus) {
            *this += -p;
            return;
        }

        size = std::max(size, p.size);
        ensureCapacity(size + 1);
        int i;
        int carry = 0;
        for (i = 0; (i < p.size || carry != 0) && i < size; i++) {
            carry += a[i] - (i < p.size ? p.a[i] : 0);
            int ncarry = 0;
            while (carry < 0) {
                carry += BASE;
                ncarry--;
            }
            a[i] = carry;
            carry = ncarry;
        }
        if (carry != 0)
            a[size++] = carry;

        if (a[size - 1] < 0) {
            for(int j = 0; j < size - 1; j++)
                a[j] = BASE - 1 - a[j];
            a[size - 1] = 0;
            for (i = 0; ; i++)
                if (++a[i] < BASE)
                    break;
                else
                    a[i] = 0;
            size = std::max(size, i + 1);
            minus ^= true;
        }
        reduce();
    }

    void operator *=(int x) {
        if (x < 0) {
            minus ^= true;
            x = -x;
        }
        int i;
        long long carry = 0;
        ensureCapacity(size + 2);
        for (i = 0; i < size || carry != 0; i++) {
            carry += i < size ? a[i] * (long long)(x) : 0;
            a[i] = int(carry % BASE);
            carry /= BASE;
        }
        size = std::max(size, i);
        reduce();
    }

    void operator /= (int x) {
        if (x == 0) {
            std::cerr << "Dividing by zero" << std::endl;
            throw 1;
        }
        if (x >= BASE)
            return operator /=(*new BigInteger(x));
        if (x < 0) {
            minus ^= true;
            x = -x;
        }
        long long carry = 0;
        for(int i = size - 1; i >= 0; i--) {
            carry = carry * BASE + a[i];
            a[i] = int(carry / x);
            carry %= x;
        }
        reduce();
    }

    int operator %(int x) const {
        if (x <= 0) {
            std::cerr << "Mod by value <= 0" << std::endl;
            throw 1;
        }
        int carry = 0;
        for(int i = size - 1; i >= 0; i--)
            carry = (carry * (long long)(BASE) + a[i]) % x;
        if (minus && carry != 0)
            carry = x - carry;
        return carry;
    }

    BigInteger operator *(const BigInteger& b) const {
#ifdef FFT_ENABLED
        int maxSize = std::max(size, b.size);
        if (maxSize > 50 && (double)size * b.size / 5 > maxSize * log(maxSize + 0.0)) {
            std::string str1 = toString(), str2 = b.toString();
            int str1minus = int(str1[0] == '-');
            int str2minus = int(str2[0] == '-');
            std::string result = FFT::multiply_solve(str1.c_str() + str1minus, str1.size() - str1minus, str2.c_str() + str2minus, str2.size() - str2minus, minus ^ b.minus);
            return BigInteger(result);
        }
#endif
        BigInteger res;
        res.ensureCapacity(size + b.size + 1);
        memset(res.a, 0, (size + b.size + 1) * sizeof(int));
        res.minus = minus ^ b.minus;
        for(int i = 0; i < size; i++) {
            int j;
            long long carry = 0;
            for(j = 0; j < b.size || carry != 0; j++) {
                carry += res.a[i + j] + (j < b.size ? a[i] * (long long)b.a[j] : 0);
                res.a[i + j] = int(carry % BASE);
                carry /= BASE;
            }
            res.size = std::max(res.size, i + j);
        }
        res.reduce();
        return res;
    }

    int compareTo(const BigInteger& p) const {
        int lf = -1, rg = +1;
        if (minus) {
            if (!p.minus)
                return -1;
            std::swap(lf, rg);
        }
        if (size != p.size)
            return size < p.size ? lf : rg;
        for(int i = size - 1; i >= 0; i--)
            if (a[i] != p.a[i])
                return a[i] < p.a[i] ? lf : rg;
        return 0;
    }

    std::pair<BigInteger, BigInteger> divide(BigInteger b) const {
        if (b.isZero()) {
            std::cerr << "Dividing by zero" << std::endl;
            throw 1;
        }
        BigInteger a = *this;
        BigInteger res;
        res.ensureCapacity(size);
        bool res_minus = a.minus ^ b.minus;
        a.minus = b.minus = false;
        int diff = std::max(0, (a.size - b.size - 1) * BASE_FFT_DIGITS);
        BigInteger pw10("1" + std::string(diff, '0'));
        b *= pw10;
        while (b <= a) {
            BigInteger nb = b * 10;
            if (nb > a)
                break;
            b = nb;
            pw10 *= 10;
        }
        while (!pw10.isZero()) {
            while (b <= a) {
                a -= b;
                res += pw10;
            }
            b /= 10;
            pw10 /= 10;
        }
        res.minus = res_minus;
        res.reduce();
        return std::make_pair(res, a);
    }

    BigInteger operator +(const BigInteger& b) const {
        BigInteger res(*this);
        res += b;
        return res;
    }

    BigInteger operator -(const BigInteger& b) const {
        BigInteger res(*this);
        res -= b;
        return res;
    }

    BigInteger operator *(int x) const {
        BigInteger res(*this);
        res *= x;
        return res;
    }

    void operator *=(const BigInteger& b) {
        *this = *this * b;
    }

    BigInteger operator /(int x) const {
        BigInteger res(*this);
        res /= x;
        return res;
    }

    void operator %=(int x) {
        *this = BigInteger(*this % x);
    }

    void operator /=(const BigInteger& p) {
        *this = divide(p).first;
    }

    BigInteger operator /(const BigInteger& p) const {
        return divide(p).first;
    }

    void operator %=(const BigInteger& p) {
        *this = divide(p).second;
    }

    BigInteger operator %(const BigInteger& p) const {
        return divide(p).second;
    }

    bool operator ==(const BigInteger& p) const {
        return compareTo(p) == 0;
    }

    bool operator !=(const BigInteger& p) const {
        return compareTo(p) != 0;
    }

    bool operator <(const BigInteger& p) const {
        return compareTo(p) < 0;
    }

    bool operator <=(const BigInteger& p) const {
        return compareTo(p) <= 0;
    }

    bool operator >(const BigInteger& p) const {
        return compareTo(p) > 0;
    }

    bool operator >=(const BigInteger& p) const {
        return compareTo(p) >= 0;
    }

    void operator ++(int) {
        operator +=(ONE);
    }

    void operator --(int) {
        operator -=(ONE);
    }

    bool operator !() const {
        return isZero();
    }

    operator bool() const {
        return !isZero();
    }

    operator std::string() const {
        return toString();
    }

    static BigInteger Multiply(int *a, int n) {
        if (n == 1)
            return BigInteger(a[0]);
        int mid = n / 2;
        return Multiply(a, mid) * Multiply(a + mid, n - mid);
    }

    static BigInteger Factorial(int n) {
        int *List = new int[n];
        for(int i = 1; i <= n; i++)
            List[i - 1] = i;
        return Multiply(List, n);
    }

    static const BigInteger ONE;
    static const BigInteger ZERO;
    static const BigInteger TEN;
    static const BigInteger MINUS_ONE;

    friend class std::pair<BigInteger, BigInteger>;
};

std::ostream &operator <<(std::ostream &out, BigInteger p) {
    return out << p.toString();
}

std::istream &operator >>(std::istream &in, BigInteger &p) {
    std::string s;
    in >> s;
    p = BigInteger(s);
    return in;
}
const int BigInteger::BASE = (int)1e9;
const int BigInteger::BASE_FFT_DIGITS = 9;

const BigInteger BigInteger::ONE = BigInteger(1LL);
const BigInteger BigInteger::ZERO = BigInteger(0LL);
const BigInteger BigInteger::TEN = BigInteger(10LL);
const BigInteger BigInteger::MINUS_ONE = BigInteger(-1LL);

BigInteger Num;

int main(){
    #ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
  //  std::ios::sync_with_stdio(false);
    int T,kase=0;
    long long N;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d",&N);
        Num=BigInteger(N);
        Num=(BigInteger(8ll)*Num-BigInteger(7ll))*Num;
        Num++;
        printf("Case #%d: ",++kase);
        string s=Num.toString();
        puts(s.c_str());
    //    cout<<"Case #"<<++kase<<": "<<Num<<endl
   //     8*n*n - 7*n + 1
    }


    return 0;
}
