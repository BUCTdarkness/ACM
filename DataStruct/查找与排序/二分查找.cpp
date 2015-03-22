//�����ظ�����ʱ����������±����� 
#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;
int find(int arr[],int low,int high,int x)
{
	while(low<high)
	{
		int mid=(low+high)/2;
		if(x>arr[mid])
		{
			low=mid+1;
		}
		else
		{
			high=mid;
		}
	}
	if(x==arr[low])
		return low;
	return -1;
}
int bs(int arr[],int l,int h,int v)
{
	int m;
	while(l<h)
	{
		m=(l+h)>>1;
		if(arr[m]==v)
			return m;
		if(arr[m]<v)
			l=m+1;
		else
			h=m;
	}
	return -1;
}
int main()
{
    int n,k,a[1001];
    while(cin>>n>>k)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        while(k--)
        {
            int v;
            cin>>v;
            cout<<find(a,0,n,v)<<" ";
        }
        cout<<endl;
    }
    return 0;
}
