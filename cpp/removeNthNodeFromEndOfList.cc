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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        ListNode dummy(0);
        dummy.next=head;
        ListNode *cur=&dummy,*pre=&dummy;
        while(cur && n--) {
            cur=cur->next;
        }
        if(n > 0)
            return head;
        while(cur->next) {
            cur=cur->next;
            pre=pre->next;
        }
        ListNode* tmp=pre->next;
        pre->next=pre->next->next;
        delete tmp;
        return dummy.next;
        
    }
};
