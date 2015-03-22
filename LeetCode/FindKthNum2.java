package com.leetcode.algorithm;

public class FindKthNum2 {
	public static int FindTheKth(int a[],int left,int right,int k){
		if(left>right) return -1;
		else if(left==right&&k!=1) return -1;
		else if(left==right&&k==1) return a[left];
		else if(k>right-left+1) return -1;
		int num = a[left],start = left ,end = right;
		while(start<end){
			while(start<end&&a[end]>num) end--;
			a[start]=a[end];
			while(start<end&&a[start]<=num) start++;
			a[end]=a[start];
		}
		a[start]=num;
		int move = start - left +1;
		if(move == k) return a[start];
		else if(move<k) return FindTheKth(a, start+1, right, k-move);
		else return FindTheKth(a, left, start-1, k);
	}
	public static void main(String []args){
		int []a={3,5,7,8,9,10};
		int k=3;
		System.out.println(FindTheKth(a, 0,a.length-1,k));
	}
}
