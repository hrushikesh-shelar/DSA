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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists==null||lists.length==0) return null;
        
        PriorityQueue<ListNode> pq = new PriorityQueue<ListNode>(lists.length, (l1, l2)-> {
            if(l1.val < l2.val) {
                return -1;
            } else if (l1.val == l2.val) {
                return 0;
            } else {
                return 1;
            }
        });
            
        ListNode ans = new ListNode(0);
        ListNode tail = ans;
        
        for(int i=0; i<lists.length; i++) {
            if(lists[i] != null) {
                pq.add(lists[i]);
            }
        }
        
        while(!pq.isEmpty()){
            ListNode t = pq.poll();
            tail.next = t;
            tail = tail.next;
            if(t.next!=null){
                pq.add(t.next);
            }
        }
        return ans.next;
    }
}