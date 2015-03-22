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
    ListNode *deleteDuplicates(ListNode *head) {
    	ListNode *p;
    	p=head;
    	if(head==NULL||head->next==NULL) return head;
    	int v=p->val;
    	while(p->next!=NULL)
    	{
    		if(v==p->next->val)
    		{
    			ListNode *q;
    			q=p->next;
    			p->next=q->next;
    			delete q;
    		}
    		else
    		{
    			v=p->next->val;
    			p=p->next;
    		}
    	}
    	return head;
    }
};