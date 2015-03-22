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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *ans=NULL;
        if(l1->val<l2->val)
        {
            ans=l1;
            ans->next=mergeTwoLists(l1->next,l2);
        }
        else
        {
            ans=l2;
            ans->next=mergeTwoLists(l1,l2->next);
        }
        return ans;
    }
    ListNode *helper(vector<ListNode*> &lists,int l,int r){
        if(l<r){
            int m=(l+r)/2;
            return(mergeTwoLists(helper(lists,l,m),helper(lists,m+1,r)));
        }
        return lists[l];
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size()==0) return NULL;
        return helper(lists,0,lists.size()-1);
    }
};
