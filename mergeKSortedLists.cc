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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode *head,*cur;
        if(l1->val < l2->val) {
            head=l1;
            l1=l1->next;
            cur=head;
        } else {
            head=l2;
            l2=l2->next;
            cur=head;
        }
        
        while(l1 &&  l2) {
            if(l1->val < l2->val) {
                cur->next=l1;
                l1=l1->next;
                cur=cur->next;
            } else {
                cur->next=l2;
                l2=l2->next;
                cur=cur->next;
            }
        }
        
        if(l1) {
            cur->next=l1;
        }
        if(l2) {
            cur->next=l2;
        }
        return head;
    }

    ListNode* mergeKListsRecur(vector<ListNode*> &lists,int start,int end) {
        if(end-start == 1)
            return lists[start];
        int mid=(start+end)/2;
        ListNode* l1=mergeKListsRecur(lists,start,mid);
        ListNode* l2=mergeKListsRecur(lists,mid,end);
        return mergeTwoLists(l1,l2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        return mergeKListsRecur(lists,0,lists.size());
    }
};
