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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode dummy(0);
        ListNode* pre=&dummy;
        while(l1 || l2) {
            int sum=(l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* cur=new ListNode(sum);
            pre->next=cur;
            pre=cur;
            l1=(l1 ? l1->next : NULL);
            l2=(l2 ? l2->next : NULL);
        }
        if(carry) {
            ListNode* cur=new ListNode(1);
            pre->next=cur;
        }
        return dummy.next;
    }
};
