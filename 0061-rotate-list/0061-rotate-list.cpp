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
    int getLengthOfList(ListNode* head) {
        int res=0;
        if(!head) {
            return res;
        }
        while(head) {
            head = head->next;
            res++;
        }
        return res;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        int lengthOfList = getLengthOfList(head);
        k = k % lengthOfList;
        if(k==0) {
            return head;
        }
        ListNode *front=head, *back=head;
        while(k--) {
            front = front->next;
        }
        while(front->next) {
            front = front->next;
            back = back->next;
        }
        front->next = head;
        head = back->next;
        back->next = nullptr;
        return head;
    }
};