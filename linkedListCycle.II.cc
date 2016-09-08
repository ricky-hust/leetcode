/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//画一个图就可以明白29到34行的逻辑
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head == NULL)
            return false;
        p1=p2=head;
        while(p1 != NULL && p2 != NULL) {
            p1=p1->next;
            if(p2->next == NULL)
                return false;
            p2=p2->next->next;
            if(p1 == p2)
                return true;
        }
    }

    ListNode *detectCycle(ListNode *head) {
        if(!hasCycle(head))
            return NULL;
        p1=head;
        while(p1 != p2) {
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
private:
    ListNode *p1,*p2;
};
