/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//这个题最主要是找到链表断开的那个地方
//记录断开点两侧的节点即可，画图很好理解
//注意这里的k可能比链表长度大
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k<=0)
            return head;
        ListNode* tail=head;
        int len=1;
        while(tail->next != NULL) {
            tail=tail->next;
            len++;
        }
        k=len-(k%len);
        if(k==len)
            return head;
        ListNode *cur,*prev;
        cur=head;
        while(k>0) {
            prev=cur;
            cur=cur->next;
            k--;
        }
        prev->next=NULL;
        tail->next=head;
        return cur;
    }
};
