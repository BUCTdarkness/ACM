package com.leetcode.algorithm;

import java.io.*;
import java.util.*;
import java.math.*;

public class MaximumGap {
	public static int maximumGap(int[] num){
		int len = num.length;
		if(len<2) return 0;		
		Arrays.sort(num);
		int ans = 0;
		for (int i=1;i<len;i++){
			ans = Math.max(ans, num[i]-num[i-1]);
		}
		return ans;
	}
	
	public static int maximumGap2(int []num){
		int len = num.length;
		if(len<2) return 0;
		int maxnum =num[0],minnum=num[0];
		for(int i=0;i<len;i++){
			maxnum = Math.max(maxnum, num[i]);
			minnum = Math.min(minnum, num[i]);
		}
		
		int gap = (int)Math.ceil((double)(maxnum-minnum)/(len-1));
		int bucketnum = (maxnum - minnum)/gap+1;
		int[] bucketmin = new int [len-1];
		int[] bucketmax = new int [len-1];
		Arrays.fill(bucketmin, Integer.MAX_VALUE);
		Arrays.fill(bucketmax, Integer.MIN_VALUE);
		
		for (int x:num){
			if(x==maxnum||x==minnum) continue;
			int index = (x - minnum)/gap;
			bucketmax[index] = Math.max(x, bucketmax[index]);
			bucketmin[index] = Math.min(x, bucketmin[index]);
		}
		
		int ans = Integer.MIN_VALUE,prenum=minnum;
//		System.out.println("bucketnum="+bucketnum);
		for (int i=0;i<bucketnum;i++){
			if(bucketmax[i]==Integer.MIN_VALUE||bucketmin[i]==Integer.MAX_VALUE)
				continue;
			ans = Math.max(ans, bucketmin[i]-prenum);
			prenum=bucketmax[i];
		}
		ans = Math.max(ans,maxnum-prenum);
		return ans;
		
	}
	
	public static void main(String []args){
		int []num ={5,3,1,6};
		System.out.println(maximumGap(num));
		System.out.println(maximumGap2(num));
	}
	
}
