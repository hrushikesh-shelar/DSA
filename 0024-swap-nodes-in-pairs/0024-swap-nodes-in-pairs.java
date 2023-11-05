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
    public ListNode swapPairs(ListNode head) {
        if(head==null || head.next==null) {
            return head;
        }
        ListNode t1 = head;
        ListNode t2 = head.next;
        ListNode newHead = head.next;
        ListNode prev = null;
        
        while(t1!=null && t2!=null) {
            t1.next=t2.next;
            t2.next=t1;
            if(prev!=null){ prev.next=t2; }
            if(t1.next==null) break;
            prev=t1;
            t1=t1.next;
            t2=t1.next;
            
        }
        return newHead;
    }
}