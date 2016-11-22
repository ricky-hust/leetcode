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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next)
            return head;
        ListNode* dummy=new ListNode(0); //it is neccessary when m=1
        dummy->next=head;
        ListNode* preNode=dummy;
        int i=1;
        while(preNode->next!=NULL && i<m) {
            i++;
            preNode=preNode->next;
        }
        if(i<m)
            return head;
        //遍历每个需要reverse的节点
        //preNode是[m,n]前的那个节点，遍历过程中让其next等于curNode节点
        //mNode是reverse的起点节点，遍历过程中让其next等于curNode的next节点
        //curNode是当前需要操作的节点，preNode->next是其原始list中的前一个节点
        //curNode从mNode的后一个节点开始
        ListNode* mNode=preNode->next;
        ListNode* curNode=mNode->next;
        while(curNode!=NULL && i<n) {
            ListNode* nextNode=curNode->next;
            curNode->next=preNode->next;
            preNode->next=curNode;
            mNode->next=nextNode;
            curNode=nextNode;
            i++;
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result; 
    }
};
