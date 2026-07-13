/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool dfs(ListNode* head, TreeNode* node)
    {
        if(head == NULL)
            return true;

        if(node == NULL)
            return false;

        if(head->val != node->val)
            return false;

        return dfs(head->next, node->left) ||
               dfs(head->next, node->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root)
    {
        if(root == NULL)
            return false;

        if(root->val == head->val)
        {
            if(dfs(head, root))
                return true;
        }

        return isSubPath(head, root->left) ||
               isSubPath(head, root->right);
    }
};