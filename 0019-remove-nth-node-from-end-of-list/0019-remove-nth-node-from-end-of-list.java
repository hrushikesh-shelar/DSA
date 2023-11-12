/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp = head;
        ListNode temp2 = head;
        while(n-- > 0) {
            temp2 = temp2.next;
        }
        if(temp2 == null) {
            return head.next;
        }
        while(temp2.next != null) {
            temp = temp.next;
            temp2 = temp2.next;
        }
        temp.next = temp.next.next;
        return head;
    }
}