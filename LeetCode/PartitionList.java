package com.leetcode.algorithm;

import java.util.*;

class ListNode{
	public int val;
	public ListNode next;
	public ListNode(int x){
		val = x;
		next = null;
	}
}

public class PartitionList {
    public ListNode partition(ListNode head, int x) {
    	if(head==null||head.next==null) return head;
    	ListNode bigger = new ListNode(0);
    	ListNode less = new ListNode(0);
    	ListNode p = less,q = bigger;
    	while(head!=null){
    		if(head.val<x){
    			p.next=head;
    			head=head.next;
    			p=p.next;
    			p.next=null;
    		}
    		else{
    			q.next=head;
    			head=head.next;
    			q=q.next;
    			q.next=null;
    		}
    	}
    	p.next=bigger.next;
    	return less.next;
    }
    
    public static void main(String []args){
    	
    }
    
}
