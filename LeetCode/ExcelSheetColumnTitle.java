package com.leetcode.algorithm;

import java.io.*;
import java.util.*;
import java.math.*;

public class ExcelSheetColumnTitle {
	
    public static String convertToTitle(int n) {
        String res = "";  
        while(n!=0)  
        {  
        	res = (char)('A' + (n-1)%26) + res;  
            n = (n) / 26;  
        }  
        return res; 
    }
    
	public static void main(String []args){
		System.out.println(convertToTitle(1000000001));
	}
}
