#include<iostream>
using namespace std;
struct BiNode
{
    char data;
    BiNode *lchild,*rchild;
    int tl,tr;
};
class Bintn
{
private:
    BiNode *root;
public:
    Bintn();
    Bintn(char e);
    ~Bintn();
    void input();
    void input(BiNode *&node);
    void Destroy();
    void Destroy(BiNode *&node);
    BiNode Headmthread();
    void Nodemthread(BiNode *h,BiNode *&prior);
    void Headmtraverse(BiNode *node);
};
