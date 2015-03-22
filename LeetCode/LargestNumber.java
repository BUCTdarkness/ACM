package com.leetcode.algorithm;

import java.util.*;

public class LargestNumber {
    public static String largestNumber(int[] num) {
    	int len = num.length;
    	if(len<1) return "";
    	String []res = new String[len];
    	for(int i=0;i<len;i++) res[i]=String.valueOf(num[i]);
    	
    	Arrays.sort(res,new Cmp());
    	String ans="";
    	for(String tmp:res){
    		ans+=tmp;
    	}
    	boolean flag = false;
    	for(int i=0;i<ans.length();i++){
    		if(ans.charAt(i)!='0'){
    			flag=true;break;
    		}
    	}
    	return flag==true?ans:"0";
    }
    public static void main(String[] args){
    	int []num={999999998,999999997,999999999};
    	System.out.println(largestNumber(num));
    }
}

class Cmp implements Comparator<String>{

	@Override
	public int compare(String a, String b) {
		// TODO Auto-generated method stub
		String ab = a+b;
		String ba = b+a;
		return (int)(Long.parseLong(ba)-Long.parseLong(ab));
	}
	
}
