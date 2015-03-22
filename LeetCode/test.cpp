#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

char *myString()
{
    char buffer[6] = {0};
    char *s = "Hello World!";
    for (int i = 0; i < sizeof(buffer) - 1; i++)
    {
        buffer[i] = *(s + i);
    }
    return buffer;
}
int main(int argc, char **argv)
{
    int i=0;printf(¡°%d%d\n¡±,i++,i--);
    printf("%s\n", myString());
    return 0;
}
