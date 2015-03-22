package com.leetcode.algorithm;

import java.util.*;

public class SurroundedRegions {
	
    private int m,n;
    private char[][] board;
    private Queue<Integer> queue = new LinkedList<Integer>();
	
    public void add(int x,int y){
    	if(x>=0&&x<m&&y>=0&&y<n&&board[x][y] == 'O'){
    		board[x][y]='Z';
    		queue.offer(x*n+y);
    	}
    }
    
    public void traversal(int x,int y){
    	add(x, y);
    	while(!queue.isEmpty()){
    		int p = queue.poll();
    		int px = p/n,py=p%n;
    		add(px-1, py);
    		add(px+1, py);
    		add(px, py-1);
    		add(px, py+1);
    	}
    }
    
	public void solve(char[][] board) {
        if(board==null||board.length==0||board[0].length==0){
        	return;
        }
        this.board=board;
        m=board.length;
        n=board[0].length;
        for(int i=0;i<n;i++){
        	traversal(0, i);
        	traversal(m-1, i);
        }
        for(int i=0;i<m;i++){
        	traversal(i, 0);
        	traversal(i, n-1);
        }
        for(int i=0;i<m;i++){
        	for(int j=0;j<n;j++){
        		board[i][j]=board[i][j]=='Z'?'O':'X';
        	}
        }
        
    }
	
	public static void main(String []args){
		
	}
}
