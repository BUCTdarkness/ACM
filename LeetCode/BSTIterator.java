package com.leetcode.algorithm;

import java.util.Stack;


class TreeNode {
     int val;
     TreeNode left;
     TreeNode right;
     TreeNode(int x) { val = x; }
}

public class BSTIterator {

	Stack<TreeNode> s = new Stack<TreeNode>();
    public BSTIterator(TreeNode root) {
       pushleft(root);
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    public int next() {
        TreeNode node = s.pop();
        pushleft(node.right);
        return node.val;
    }
    private void pushleft(TreeNode root){
    	if(root!=null){
    		s.push(root);
    		TreeNode cur = root;
    		while(cur.left!=null){
    			s.push(cur.left);
    			cur=cur.left;
    		}
    	}
    }
    
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = new BSTIterator(root);
 * while (i.hasNext()) v[f()] = i.next();
 */