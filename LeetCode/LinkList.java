package com.leetcode.algorithm;

public class LinkList {
	public static void relocateList(ListNode head) {
		if(head.next==null) return;
		ListNode cur = head;
		int len =0;
		while(cur!=null){
			len++;
			cur=cur.next;
		}
		ListNode left =head,right=head,preright =head;
		int cc =0;
		while(cc< len/2 ){
			cc++;
			preright=right;
			right=right.next;
		}
		preright.next=null;
		while(left.next!=null){
			ListNode tmpNode = right;
			ListNode nextleft = left.next;
			right = right.next;
			tmpNode.next=nextleft;
			left.next=tmpNode;
			left = nextleft;
		}
		left.next=right;
		
	}
	public static void main(String []args){
		ListNode a1 =new ListNode(1);
		ListNode a2 =new ListNode(2);
		ListNode a3 =new ListNode(3);
		ListNode a4 =new ListNode(4);
		a1.next=a2;a2.next=a3;a3.next=a4;
		a4.next=null;
		relocateList(a1);
		while(a1!=null){
			System.out.println(a1.val);
			a1=a1.next;
		}
		
	}
}
