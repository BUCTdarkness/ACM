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
	ListNode* reverve(ListNode *head){   //单链表反转
		if(head==NULL||head->next==NULL) return head;
		ListNode *tmp=reverve(head->next);
		head->next->next=head;
		head->next=NULL;
		return tmp;
	}
    void reorderList(ListNode *head) {
        if(head==NULL||head->next==NULL) return;
        ListNode *pfast=head,*pslow=head;
        while(pfast!=NULL){
        	if(pfast) pfast=pfast->next;
        	if(pfast) pfast=pfast->next;
        	if(pfast==NULL) break;
        	if(pslow) pslow=pslow->next;
        }
        ListNode *head2=reverve(pslow->next);
        pslow->next=NULL;
        ListNode *p1=head,*p2=head2;
        while(p1!=NULL&&p2!=NULL){
        	ListNode *tmp=p1->next;
        	p1->next=p2;
        	p1=tmp;
        	tmp=p2->next;
        	p2->next=p1;
        	p2=tmp;
        }
    }
};
