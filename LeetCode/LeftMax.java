package com.leetcode.algorithm;

public class LeftMax {
	public static int getMaxABSLeftAndRight(int[] arr) {
		int n = arr.length;
		if(n<=1) return 0;
		int maxv = arr[0];
		for(int i=0;i<n;i++){
			maxv = Math.max(maxv, arr[i]);
		}
        return  maxv -Math. min(arr[0], arr[n - 1]);
	}
	public static void main(String []args){
		int []arr = {2,7,3,1,1};
		System.out.println(getMaxABSLeftAndRight(arr));
	}
}
