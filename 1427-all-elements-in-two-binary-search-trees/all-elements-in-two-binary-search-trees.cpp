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
void solve(TreeNode* root2,vector<int> &f)
{
    if(root2 == NULL) return;
    fun(root2->left,f);
    f.push_back(root2->val);
    fun(root2->right,f);
}
void fun(TreeNode* root1,vector<int> &f)
{
    if(root1 == NULL) return;
    fun(root1->left,f);
    f.push_back(root1->val);
    fun(root1->right,f);
}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>f;
        fun(root1,f);
        solve(root2,f);
        sort(f.begin(),f.end());
        return f;

    }
};