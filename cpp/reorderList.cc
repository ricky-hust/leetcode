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
        ListNode dummy(0);
        ListNode* cur=head;
        while(cur) {
            ListNode* prehead=dummy.next;
            dummy.next=cur;
            ListNode* next=cur->next;
            cur->next=prehead;
            cur=next;
        }
        return dummy.next;
    }
    
    void mergeList(ListNode* l1,ListNode* l2) {
        while(l2) {
            ListNode* tmp=l1->next;
            ListNode* next=l2->next;
            l1->next=l2;
            l2->next=tmp;
            l1=tmp;
            l2=next;
        }
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        ListNode dummy(0);
        dummy.next=head;
        ListNode *slow=&dummy,*fast=&dummy;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head2=slow->next;
        slow->next=NULL;
        head2=reverseList(head2);
        mergeList(head,head2);
    }
};
