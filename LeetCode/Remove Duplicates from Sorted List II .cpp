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
        if(head==NULL||head->next==NULL) return head;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *pre=dummy;
        ListNode *cur=head;
        while(cur!=NULL&&cur->next!=NULL)
        {
        	if(cur->next->val==cur->val)
        	{
        		while(cur->next!=NULL&&cur->next->val==cur->val)
        		{
        			cur=cur->next;
        		}
        		pre->next=cur->next;
        		ListNode *tmp=cur;
        		cur=cur->next;
        		delete tmp;
        	}
        	else
        	{
        		pre=cur;
        		cur=cur->next;
        	}
        }
        return dummy->next;
    }
};
