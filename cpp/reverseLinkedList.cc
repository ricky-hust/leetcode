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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *cur,*prev;
        prev=NULL;
        cur=head;
        while(cur) {
            ListNode* tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;
        }
        return prev;//here should be prev
    }
};
