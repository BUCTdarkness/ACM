package com.leetcode.algorithm;

import java.io.*;
import java.math.*;
import java.util.*;
import java.util.Map.Entry;

public class RepeatedDNASequences {
	
    
	private static int String2Integer(String st){
        String str = st;
        int s=0;
        for(int i=0;i<str.length();i++){
        	if(str.charAt(i)=='A'){
        		s=s*4+0;
        	}
        	else if(str.charAt(i)=='C'){
        		s=s*4+1;
        	}
        	else if(str.charAt(i)=='G'){
        		s=s*4+2;
        	}
        	else if(str.charAt(i)=='T'){
        		s=s*4+3;
        	}
        }
        return s;
	}
	
	public static List<String> findRepeatedDnaSequences(String s) {
        List<String> ans = new ArrayList<String>();
        int []vis=new int[1048576];
        for(int i=0;i<1000;i++) vis[i]=0;
        int len = s.length();
        for(int i=0;i<len-10+1;i++){
        	String tmp = s.substring(i, i+10);
        	int tString = String2Integer(tmp);
        //	System.out.println(tString);
        	vis[tString]++;
        	if(vis[tString]>1){
        	    if(!ans.contains(tmp))
        		ans.add(tmp);
        	}
        }
        
    	return ans;
    }	
	
	public static void main(String []args){
		//work();
		String string = "AAAAAAAAAAA";
		System.out.println(findRepeatedDnaSequences(string));
	}
}
