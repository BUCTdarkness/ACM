#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=100001;
struct Array
{
	int length;
	int r[maxn];
};
/*
void Merge(int sr[],int tr[],int i,int m,int n)
{
	int j,k;
	for(j=m+1,k=i;i<=m&&j<=n;++k)
	{
		if(sr[i]<=sr[j])
			tr[k]=sr[i++];
		else
			tr[k]=sr[j++];
	}
	if(i<=m)
	{
		while(k<=n&&i<=m)
		{
			tr[k++]=sr[i++];
		}
	}
	if(j<=n)
	{
		while(k<=n&&j<=n)
		{
			tr[k++]=sr[j++];
		}
	}
}
void MSort(int sr[],int tr1[],int s,int t)
{
	int m;
	int *tr2;
	tr2=new int [maxn];
	if(s==t)
	{
		tr1[t]=sr[s];
	} 
	else
	{
		m=(s+t)/2;
		MSort(sr,tr2,s,m);
		MSort(sr,tr2,m+1,t);
		Merge(tr2,tr1,s,m,t);
	}
	delete []tr2;
}
void MergeSort(Array &L)
{
	MSort(L.r,L.r,1,L.length);
}*/
void Merge(int *a, int p, int q, int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	int *L = new int[n1+1];
	int *R = new int[n2+1];
	int i, j, k;
	
	for (i=0; i<n1; i++){
		L[i] = a[p+i];
	}
	cout<<endl;
	for (j=0; j<n2; j++){
		R[j] = a[q+j+1];
	}
	cout<<endl;
	L[n1] = 10000000;
	R[n2] = 10000000;

	for (i=0, j=0, k=p; k<=r; k++)
	{
		if (L[i]<=R[j])
		{
			a[k] = L[i];
			i++;
		}else{
			a[k] = R[j];
			j++;
		}
	}

	delete []L;
	delete []R;
}

void MergeSort(int *a, int p, int r)
{
	if (p<r)
	{
		int q = (p+r)/2;
		MergeSort(a, p, q);
		MergeSort(a, q+1, r);
		Merge(a, p, q, r);
	}
}
int main()
{
	Array L;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		L.length=n;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&L.r[i]);
		}
		MergeSort(L.r,0,L.length-1);
		for(int i=0;i<n;i++)
		{
			printf("%d ",L.r[i]);
		}
		printf("\n");
	}
	return 0;
}
