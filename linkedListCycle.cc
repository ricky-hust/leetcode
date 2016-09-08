/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode* p1;
    struct ListNode* p2;

    if (head==NULL) return false;
    p1=head;
    p2=head;

    while (p1!=NULL && p2!=NULL){

        p1=p1->next;

        if (p2->next == NULL) return false;

        p2=p2->next->next;

        if (p1==p2) return true;
    }

    return false;

}
