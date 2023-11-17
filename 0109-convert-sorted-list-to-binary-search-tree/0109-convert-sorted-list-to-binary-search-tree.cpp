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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }   
        if(head->next==nullptr){
            return new TreeNode(head->val);
        }
        
        ListNode *slowPtr=head, *fastPtr=head, *prev=head;
        while(fastPtr and fastPtr->next) {
            fastPtr=fastPtr->next->next;
            if(prev!=slowPtr){
                prev=prev->next;
            }
            slowPtr=slowPtr->next;
        }
        
//         cout << "slowPtr: " << slowPtr->val;
// if (fastPtr) {
//     cout << " fastPtr: " << fastPtr->val;
// }
// if (prev) {
//     cout << " prev: " << prev->val;
// }
//         cout <<endl;
        prev->next=nullptr;
        TreeNode* root = new TreeNode(slowPtr->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slowPtr->next);
        return root;
    }
};