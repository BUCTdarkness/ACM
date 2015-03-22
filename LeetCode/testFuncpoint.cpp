#include <iostream>
using namespace std;
void PreOrderTraverse(int t)
{
    cout<<t<<endl;
}
void InOrderTraverse(int t)
{
    cout<<t<<endl;
}
void SucOrderTraverse(int t)
{
    cout<<t<<endl;
}

typedef void(Func)(int);
void solve1(Func f){
	f(1);
}
void solve2(Func f){
	f(2);
}
void solve3(Func f){
    f(3);
}
int main(){
    solve1(PreOrderTraverse);
    solve2(InOrderTraverse);
    solve3(SucOrderTraverse);
}

