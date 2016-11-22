/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//使用数组merge sort的思路时间复杂度:O(T(n)) = 2O(T(n/2)) + O(n)
class Solution {
public:
    ListNode* mergeTwoSortedLists(ListNode* l1,ListNode* l2) {
        ListNode dummy(0),*cur=&dummy;
        while(l1 && l2) {
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
        if(l1)
            cur->next=l1;
        if(l2)
            cur->next=l2;
        return dummy.next;
    }

    ListNode* listMiddle(ListNode* head) {
        ListNode *slow,*fast;
        slow=fast=head;
        while(fast->next && fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* mid=listMiddle(head);
        ListNode* head2=mid->next;
        mid->next=NULL;
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(head2);
        return mergeTwoSortedLists(l1,l2);
    }
};
