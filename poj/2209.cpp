#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int num, b, i, s, ans, tmp;
    while (cin >> num >> b){
          ans = 0;
          for (i = 0; i < num; i++){
              cin >> s;
              tmp = pow(s, (float)b);
              ans += (tmp > 0 ? tmp : 0);
          }
          cout << ans << endl;
    }
    return 0;
}
