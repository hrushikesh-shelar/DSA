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
    public ListNode swapNodes(ListNode head, int k) {       
        ListNode temp1 = head;
        ListNode temp2 = head;
        k = k-1;
        while(k-- > 0) {
            temp2 = temp2.next;
        }
        if(temp2 == null) {
            return head;
        }
        ListNode node1 = temp2;
        while(temp2.next != null) {
            temp1 = temp1.next;
            temp2 = temp2.next;
        }
        ListNode node2 = temp1;
        int valtemp = node1.val;
        node1.val = node2.val;
        node2.val = valtemp;
        return head;
    }
}