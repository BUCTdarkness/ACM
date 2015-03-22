package com.leetcode.algorithm;

public class RotateArray {
    
	public static void moveRight(int nums[],int len){
		if(len==0) return;
		int tmp = nums[len-1];
		for(int i=len-1;i>=1;--i) nums[i]=nums[i-1];
		nums[0]=tmp;
	}
	public static void rotate(int[] nums, int k) {
        int len = nums.length;
        for(int i=0;i<k;++i){
        	moveRight(nums,len);
        }
    }
	
	
	public static void main(String []args){
		int []nums={1,2,3,4,5,6,7};
		int k=3;
		rotate(nums, k);
		for(int i=0;i<nums.length;i++) System.out.println(nums[i]);
	}
}
