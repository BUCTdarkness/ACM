package com.leetcode.algorithm;

import java.io.IOException;
import java.util.*;


public class EvaluateReversePolishNotation {
	public static int evalRPN1(String[] tokens) {
		int returnValue = 0;
		String operators = "+-*/";
 
		Stack<String> stack = new Stack<String>();
 
		for (String t : tokens) {
			if (!operators.contains(t)) {
				stack.push(t);
			} else {
				int a = Integer.valueOf(stack.pop());
				int b = Integer.valueOf(stack.pop());
				switch (t) {
				case "+":
					stack.push(String.valueOf(a + b));
					break;
				case "-":
					stack.push(String.valueOf(b - a));
					break;
				case "*":
					stack.push(String.valueOf(a * b));
					break;
				case "/":
					stack.push(String.valueOf(b / a));
					break;
				}
			}
		}
 
		returnValue = Integer.valueOf(stack.pop());
 
		return returnValue;
	}
	
    public static int evalRPN(String[] tokens){
    	int ans = 0;
    	Stack<String> stack = new Stack<String>();
    	String operators = "+-*/";
    	for(String tmp:tokens){
    		if(operators.contains(tmp)){
    			int a = Integer.valueOf(stack.pop());
    			int b = Integer.valueOf(stack.pop());
    			switch (tmp) {
				case "+":
					stack.push(String.valueOf(a+b));
					break;
				case "-":
					stack.push(String.valueOf(b-a));
					break;
				case "*":
					stack.push(String.valueOf(a*b));
					break;
				case "/":
					stack.push(String.valueOf(b/a));
					break;
				}
    		}
    		else{
    			stack.push(tmp);
    		}
    	}
    	ans = Integer.valueOf(stack.pop());
    	return ans;
    }
    
	public static void main(String[] args){
		String[] tokens = new String[] { "0", "3", "/" };
		System.out.println(evalRPN(tokens));
	}
}
