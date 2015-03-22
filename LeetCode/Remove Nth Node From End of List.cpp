/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head==NULL) return NULL;
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *p=dummy->next,*prep=dummy,*q=dummy->next;
        for(int i=0;i<n;i++) q=q->next;
        while(q!=NULL){
        	q=q->next;
        	prep=p;
        	p=p->next;
        }
        prep->next=p->next;
    	delete p;
    	return dummy->next;
    }
};
