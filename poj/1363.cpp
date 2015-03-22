#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

#define maxn 1005

int n;
int f[maxn];

void input()
{
    for (int i = 1; i < n; i++)
        scanf("%d", &f[i]);
}

bool ok()
{
    stack<int> stk;
    int temp = 1;
    for (int i = 0; i < n; i++)
    {
        while (temp <= f[i])
            stk.push(temp++);
        int x = stk.top();
        stk.pop();
        if (x != f[i])
            return false;
    }
    return true;
}

int main()
{
    //freopen("t.txt", "r", stdin);
    while (scanf("%d", &n), n)
    {
        while (scanf("%d", &f[0]), f[0])
        {
            input();
            if (ok())
                puts("Yes");
            else
                puts("No");
        }
        puts("");
    }
    return 0;
}
