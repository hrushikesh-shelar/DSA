/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Map<ListNode, Boolean> mp = new HashMap<>();
        ListNode t = headA;
        while(t != null) {
            mp.put(t, true);
            t = t.next;
        }
        t = headB;
        while(t != null) {
            if(mp.containsKey(t)){
                return t;
            }
            t = t.next;
        }
        return null;
    }
}