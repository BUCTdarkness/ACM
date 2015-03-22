package com.leetcode.algorithm;

import java.io.*;
import java.util.*;
import java.math.*;

public class ExcelSheetColumnNumber {
	
    public static int titleToNumber(String s) {
    	int ans = 0,len = s.length();
    	for (int i=0;i<len;i++){
    		int tmp = s.charAt(i)-'A'+1;
    		ans += tmp * Math.pow(26.0, len - i -1);
    	}
    	return ans;
    }
    
    public static void main(String []args){
    	System.out.println(titleToNumber("A"));
    }
    
}
