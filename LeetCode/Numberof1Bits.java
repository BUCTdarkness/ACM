package com.leetcode.algorithm;

public class Numberof1Bits {
    public static int hammingWeight(int n) {
    	int ans = 0;
    	while(n!=0){
    		ans++;
    		n&=(n-1);
    	}
        return ans;
    }
    
	public static void main(String []args){
		System.out.println(hammingWeight(11));
	}
}
