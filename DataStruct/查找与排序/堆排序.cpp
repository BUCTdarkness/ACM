//建初始堆时，由于最后一个非终结端结点是第 n/2个元素，由此筛选从第n/2个元素开始。 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=100005;
struct HeapType
{
	int length;
	int r[MAXN];
};
	int n;
void HeapAdjust(HeapType &H,int s,int m)
{
	int rc;
	rc=H.r[s];
	for(int j=2*s;j<m;j*=2)
	{
		if(j<m&&H.r[j]<H.r[j+1])
			++j;
		if(rc>=H.r[j])
			break;
		H.r[s]=H.r[j];
		s=j;
	}
	H.r[s]=rc;
}
void HeapSort(HeapType &H)
{
	int i;
	int temp;
	for(int i=(H.length-1)/2;i>=0;i--)
	{
		HeapAdjust(H,i,H.length);
	}
	for(int i=H.length-1;i>0;i--)
	{
		temp=H.r[i];
		H.r[i]=H.r[0];
		H.r[0]=temp;
		HeapAdjust(H,0,i-1);
	}
}
int main()
{

	HeapType H;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>H.r[i];
		}
		H.length=n;
		HeapSort(H);
		for(int i=0;i<n;i++)
		{
			cout<<H.r[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
         