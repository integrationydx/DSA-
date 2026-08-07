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
vector<int>f;
void fun(TreeNode * root)
{
    if(root == NULL) return;
    fun(root->left);
    f.push_back(root->val);
    fun(root->right);
}
    int minDiffInBST(TreeNode* root) {
        fun(root);
        int mini = INT_MAX;
        for(int i=1;i<f.size();i++)
        {
           mini = min(mini,abs(f[i]-f[i-1]));
        }
        return mini;
    }
};