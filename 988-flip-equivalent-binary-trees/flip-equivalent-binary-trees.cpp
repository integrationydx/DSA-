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

bool fun(TreeNode* root1, TreeNode* root2)
{
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL && root2 != NULL) return false;
    if(root1 != NULL && root2 == NULL) return false;

    if(root1->val != root2->val)
        return false;

    if(fun(root1->left, root2->left) &&
       fun(root1->right, root2->right))
    {
        return true;
    }

    if(fun(root1->left, root2->right) &&
       fun(root1->right, root2->left))
    {
        return true;
    }

    return false;
}

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
       return fun(root1,root2);
    }
};