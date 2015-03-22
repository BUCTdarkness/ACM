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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head=NULL,*tail=NULL;
        int c=0;
        while(l1!=NULL||l2!=NULL||c!=0){
        	if(l1){
        		c+=l1->val;
        		l1=l1->next;
        	}
        	if(l2){
        		c+=l2->val;
        		l2=l2->next;
        	}
        	ListNode *p=new ListNode(c%10);
        	if(head==NULL) head=p;
        	else tail->next=p;
        	tail=p;
        	c/=10;
        }
        return head;
    }
};
