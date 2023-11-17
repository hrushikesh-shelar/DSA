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
    ListNode* deleteMiddle(ListNode* head) {
        if( head==nullptr or head->next==nullptr ) {
            return nullptr;
        }
        ListNode *slowPtr=head, *fastPtr=head, *prev=head;
        while(fastPtr && fastPtr->next) {
            fastPtr = fastPtr->next->next;
            if(prev!=slowPtr) prev = prev->next;
            slowPtr = slowPtr->next;
        }
        prev->next=slowPtr->next;
        return head;
    }
};