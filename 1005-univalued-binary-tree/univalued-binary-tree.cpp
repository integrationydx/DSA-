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

    bool isUnivalTree(TreeNode* root) {
        unordered_map<int,int>mp;
        fun(root);
         for(int i=0;i<f.size();i++)
        {
            mp[f[i]]++;
        }
        if(mp.size()>1) return false;
        return true;
    
    }
};