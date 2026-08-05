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
void fun(TreeNode *root,vector<int> &f)
{
    if(root == NULL) return;
    fun(root->left,f);
    f.push_back(root->val);
    fun(root->right,f);
}
    int rangeSumBST(TreeNode* root, int low, int high) {
      
        fun(root,f);
      int sumi = 0;
        for(int i=0;i<f.size();i++)
        {
            if(f[i]>=low && f[i]<=high)
            {
                 sumi+= f[i];
            }
          
        }
        return sumi;
    }
};