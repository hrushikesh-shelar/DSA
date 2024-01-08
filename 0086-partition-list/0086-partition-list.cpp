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
    ListNode* partition(ListNode* head, int x) {
        ListNode *greaterHead, * lesserHead;
        greaterHead = new ListNode(0);
        lesserHead = new ListNode(0);
        
        ListNode *greater=greaterHead, * lesser=lesserHead;
        
        ListNode* curr = head;
        while(curr) {
            if(curr->val<x) {
                ListNode* temp = new ListNode(curr->val);
                lesser->next = temp;
                lesser = lesser->next;
            } else {
                ListNode* temp = new ListNode(curr->val);
                greater->next = temp;
                greater = greater->next;
            }
            curr = curr->next;
        }
        lesser->next = greaterHead->next;
        ListNode* res = lesserHead->next;
        return res;
    }
};