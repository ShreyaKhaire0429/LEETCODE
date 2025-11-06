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
    // Shreya
public:
// Shreya
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;                // Empty list
        if (!head->next) return new TreeNode(head->val);  // Single node

        ListNode *slow = head, *fast = head, *prev = nullptr;

        // Find the middle node
        while (fast && fast->next) 
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect the left half from the middle
        if (prev) prev->next = nullptr;

        // Create root node
        TreeNode* root = new TreeNode(slow->val);

        root->left = sortedListToBST((slow != head) ? head : nullptr);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};
