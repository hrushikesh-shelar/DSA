/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* curr = dummyHead;
        while(curr) {
            ListNode* nextNode = curr->next;
            if(nextNode && nextNode->next && nextNode->val==nextNode->next->val) {
                int nextVal = nextNode->val;
                while(nextNode && nextNode->val==nextVal)
                    nextNode=nextNode->next;
                curr->next = nextNode;
            } else {
                curr = curr->next;   
            }
        }
        return dummyHead->next;
    }
};