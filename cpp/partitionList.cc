/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//单链表的题目一般是一个遍历，在这个遍历遵循循环不等式
//这个题lt和gt分别为小于和大于x的链表的最后一个节点，这两个链表连接在一起
//为了让初始的lt和gt满足循环不等式，构造了dummyMin和dummyMax两个虚拟几点
//最后需要将dummyMax delete掉，35行完成这个
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummyMin(INT_MIN);
        ListNode dummyMax(INT_MAX);
        ListNode *lt=&dummyMin,*gt=&dummyMax;
        dummyMin.next=&dummyMax;
        ListNode *cur=head;
        while(cur) {
            ListNode* next=cur->next;
            if(cur->val < x) {
                ListNode* tmp=lt->next;
                lt->next=cur;
                cur->next=tmp;
                lt=cur;
            } else {
                gt->next=cur;
                cur->next=NULL;
                gt=cur;
            }
            cur=next;
        }
        lt->next=lt->next->next;
        return dummyMin.next;
    }
};
