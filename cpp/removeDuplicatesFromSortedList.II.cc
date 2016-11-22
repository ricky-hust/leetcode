/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//循环不变式+状态机转换的思想
//这里循环不变式的结束后还需要自己处理一下
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next=head;
        ListNode* pre=&dummy;
        ListNode* cur=head;
        bool dup=false;
        while(cur && cur->next) {
            if(dup==false && cur->val == cur->next->val) {
                dup=true;
                cur=cur->next;
            } else if(dup==true && cur->val == cur->next->val) {
                cur=cur->next;
            } else if(dup==false && cur->val != cur->next->val) {
                pre->next=cur;
                pre=pre->next;
                cur=cur->next;
            } else { //dup==true && cur->val != cur->next->val
                dup=false;
                cur=cur->next;
            }
        }
        if(dup==false)
            pre->next=cur;
        else
            pre->next=NULL;
        return dummy.next;
    }
};
