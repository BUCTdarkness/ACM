package com.leetcode.algorithm;

public class GasStation {
	
    public static int canCompleteCircuit(int[] gas, int[] cost) {
    	int total = 0,len = gas.length,sum=0,stmax=0;
    	for(int i =0 ;i<len;i++){
    		total += gas[i]-cost[i];
    		if(sum<0){
    			sum=gas[i]-cost[i];
    			stmax=i;
    		}
    		else{
    			sum +=gas[i]-cost[i];
    		}
    	}
        return total<0?-1:stmax;
    }
	public static void main(String []args){
		
	}
}
