package com.leetcode.algorithm;

public class ReverseBits {
    public static int reverseBits(int n) {
        int ans = 0;
        for(int i=0;i<32;i++){
        	ans |=((n>>i)&1)<<(31-i);
        }
        return ans;
    }
	public static void main(String []args){
		System.out.println(reverseBits(43261596));
	}
}
