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
    ListNode *partition(ListNode *head, int x) {
        
    	if(head==NULL||head->next==NULL) return head;
    	ListNode *bigger=new ListNode(0);
    	ListNode *less=new ListNode(0);
    	ListNode *p=less,*q=bigger;
    	while(head!=NULL)
    	{
    		if(head->val<x)
    		{
    			p->next=head;
    			head=head->next;
    			p=p->next;
    			p->next=NULL;
    		}
    		else
    		{
    			q->next=head;
    			head=head->next;
    			q=q->next;
    			q->next=NULL;
    		}
    	}
    	p->next=bigger->next;
    	return less->next;
    }
};