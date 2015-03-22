#include <iostream>
using namespace std;
#define MY_MAX 1100
intTree[MY_MAX * 3][MY_MAX * 3];//二维线段树，每一行都是一棵完全二叉树，用于存放一棵x方向线段树，树节点只存放对应的区间（矩阵）的数字之和intS; //矩阵宽度void Add_x( introoty,introotx, intL, intR, intx ,inta)//tree[rooty][rootx]对应的矩阵x方向上范围是[L,R]{Tree[rooty][rootx] += a;if( L == R ) return;intmid = (L + R )/2;if( x <= mid )Add_x(rooty,( rootx<< 1) + 1, L ,mid, x, a);elseAdd_x(rooty,( rootx<< 1) + 2, mid + 1,R, x, a);}