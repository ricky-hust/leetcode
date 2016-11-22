/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode dummyHead1=new ListNode(0);
        ListNode dummyHead2=new ListNode(0);
        ListNode tail1=dummyHead1,tail2=dummyHead2;
        ListNode cur=head;
        while(cur != null) {
            ListNode tmp=cur.next;
            if(cur.val<x) {
                tail1.next=cur;
                cur.next=null;
                tail1=cur;
            } else {
                tail2.next=cur;
                cur.next=null;
                tail2=cur;
            }
            cur=tmp;
        }
        tail1.next=dummyHead2.next;
        return dummyHead1.next;
    }
}
