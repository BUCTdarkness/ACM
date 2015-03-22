package com.leetcode.algorithm;

import java.util.*;

public class RemoveDuplicatesfromSortedArrayII {
    public static int removeDuplicates(int[] A) {
        int len=0;
        Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
        for(int i=0;i<A.length;i++){
        	if(mp.containsKey(A[i])&&mp.get(A[i])>=2) continue;
        	if(mp.containsKey(A[i])){
        		mp.put(A[i],mp.get(A[i])+1 );
        	}
        	else{
        		mp.put(A[i], 1);
        	}
        	A[len++]=A[i];
        }
        return len;
    }
    public static void main(String[]args){
    	int []A={1,1,1,2,2,3};
    	System.out.println(removeDuplicates(A));
    }
}
