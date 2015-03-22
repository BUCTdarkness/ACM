package com.leetcode.algorithm;

import java.util.*;

public class WordBreak {
    public static boolean wordBreak(String s, Set<String> dict) {
    	if(s.length()==0) return true;
    	boolean []dp = new boolean[s.length()+1];
    	for(int i=0;i<dp.length;i++) dp[i]=false;
    	dp[0]=true;
    	int len = s.length();
    	for(int i=1;i<=len;i++){
    		if(dp[i-1]){
    			for(int j=i-1;j<len;j++){
    				String tmp = s.substring(i-1, j+1);
    				System.out.println(tmp);
    				if(dict.contains(tmp)){
    					dp[j+1]=true;
    				}
    			}
    		}
    	}
    	return dp[len];
    }
    
    public static void main(String []args){
    	String s = "leetcode";
    	Set<String> dict=new HashSet<String>();
    	dict.add("leet");
    	dict.add("code");
    	System.out.println(wordBreak(s,dict));
    }
}
