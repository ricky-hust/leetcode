/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//这个题初始化情况是一个空链表，使用一个dummy节点来代表，0(dummy) -> NULL
//此后的循环不等式就是在cur之前的是一个排好序的list:0(dummy) -> sorted list -> NULL
//一定要注意这里的NULL!
//将cur加入到sorted list中，只需要pre节点即可
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode* cur=head;
        while(cur) {
            ListNode *pre=&dummy;
            while(pre->next && pre->next->val < cur->val) {
                pre=pre->next;
            }
            ListNode* next=cur->next;
            ListNode* tmp=pre->next;
            pre->next=cur;
            cur->next=tmp;
            cur=next;
        }
        return dummy.next;
    }
};
