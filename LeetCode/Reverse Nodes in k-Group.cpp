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
    ListNode *reverseKGroup(ListNode *head, int k) {
    	if(k<2||head==NULL||head->next==NULL) return head;
    	ListNode *phead=head,*ptail=NULL;
    	ListNode *p=head,*tmp=NULL;
    	int cnt=0;
    	while(p!=NULL){
    		cnt++;
    		if(cnt==k){
    			tmp=p->next;
    			p->next=NULL;
    			if(ptail==NULL) head=reverse(phead);
    			else ptail->next=reverse(phead);
    			ptail=phead;
    			phead=tmp;
    			p=phead;
    			cnt=0;
    		}
    		else{
    			p=p->next;
    		}
    	}
    	if(ptail!=NULL){
    		ptail->next=phead;
    	}
    	return head;
    }
private:
	ListNode *reverse(ListNode *head){
        if(head==NULL||head->next==NULL) return head;
        ListNode *tmphead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return tmphead;
	}
};
