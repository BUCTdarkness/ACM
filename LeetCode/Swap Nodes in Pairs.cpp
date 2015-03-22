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
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL) return head;
        ListNode *p1=head,*p2=head->next,*tmp=NULL,*last=NULL;
        if(p2!=NULL) head=p2; else return head;
        while(p1!=NULL&&p2!=NULL){
        	if(last!=NULL) last->next=p2;
        	tmp=p2->next;
        	p1->next=tmp;
        	p2->next=p1;
        	last=p1;
        	p1=tmp;
        	if(p1!=NULL) p2=p1->next;
        	else break;
        }
        return head;
    }
};
