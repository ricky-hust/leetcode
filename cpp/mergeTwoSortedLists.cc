/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//有点类似于merge sort中的merge过程
//cur表示新的list中的当前节点，l1和l2代表当前需要比较的节点
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
};
