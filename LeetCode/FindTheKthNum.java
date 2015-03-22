package com.leetcode.algorithm;

public class FindTheKthNum {
	public static void main(String []args){
		int []a={3,5,7,8,9,10};
		int []b={2,4,5,7,9};
		int k=3;
		System.out.println(FindTheKth(a, b, 0, a.length-1, 0, b.length-1, k));
	}
	public static int FindTheKth(int a[],int b[],int aleft,int aright,int bleft,int bright,int k){
		int amid = (aleft+aright)/2,bmid = (bleft+bright)/2;
		if(aleft>aright) return b[bleft+k-1];
		if(bleft>bright) return a[aleft+k-1];
		int x=amid-aleft,y=bmid-bleft;
		if(a[amid]<=b[bmid]){
			if(k<=x+y+1){return FindTheKth(a, b, aleft, aright, bleft, bmid-1, k);}
			else{return FindTheKth(a, b, amid+1, aright, bleft, bright, k-x-1);}
		}
		else{
			if(k<=x+y+1){return FindTheKth(a, b, aleft, amid-1, bleft, bright, k);}
			else{return FindTheKth(a, b, aleft, aright, bmid+1, bright, k-y-1);}
		}
	}
}
