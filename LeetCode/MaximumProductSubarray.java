package com.leetcode.algorithm;

import java.io.*;
import java.util.*;
import java.math.*;


public class MaximumProductSubarray {

	public static int maxProduct(int[] A){
		int len =A.length;
		if(len<1) return 0;
		int maxnum=A[0],minnum=A[0],ans = A[0];
		for (int i=1; i<len;i++){
			int tmp =maxnum;
			maxnum = Math.max(Math.max(maxnum*A[i],A[i]), minnum*A[i]);
			minnum = Math.min(Math.min(tmp*A[i], A[i]), minnum*A[i]);
			ans = Math.max(ans, maxnum);
		}
		return ans;
	}
	public static void main(String []args){
		int []A ={2,3,-2,4};
		System.out.println(maxProduct(A));
	}
}
