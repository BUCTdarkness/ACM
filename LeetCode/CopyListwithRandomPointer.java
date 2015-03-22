package com.leetcode.algorithm;

class RandomListNode {
    int label;
    RandomListNode next, random;
    RandomListNode(int x) { this.label = x; }
};

public class CopyListwithRandomPointer {
	
    public RandomListNode copyRandomList(RandomListNode head) {
    	if(head==null) return head;
    	RandomListNode curNode = head;
    	while(curNode!=null){
    		RandomListNode copyNode = new RandomListNode(curNode.label);
    		copyNode.random=curNode.random;
    		copyNode.next=curNode.next;
    		curNode.next=copyNode;
    		curNode=copyNode.next;
    	}
    	
    	curNode = head;
    	while(curNode!=null){
    		if(curNode.random!=null){
    			curNode.next.random=curNode.random.next;
    		}
    		curNode=curNode.next.next;
    	}
    	
    	RandomListNode pHead = new RandomListNode(0);
    	pHead.next=head;
    	RandomListNode newList = pHead;
    	curNode = head;
    	while(curNode!=null){
    		pHead.next=curNode.next;
    		curNode.next=pHead.next.next;
    		pHead=pHead.next;
    		curNode=curNode.next;
    	}
    	return newList.next;
    }	
	public static void main(String args[]){
		
	}
}
