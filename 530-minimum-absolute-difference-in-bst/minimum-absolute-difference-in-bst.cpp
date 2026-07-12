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
void fun(TreeNode*root,vector<int> &ans)
{
   if(root == NULL) return;

   fun(root->left,ans);
   ans.push_back(root->val);
   fun(root->right,ans);
}

    int getMinimumDifference(TreeNode* root) {
        vector<int>ans;
         fun(root,ans);
         if(ans.size() == 0) return -1;
         if(ans.size() == 1) return -1;
         int n = ans.size() -1;
       int mini = INT_MAX;
       for(int i=1;i<ans.size();i++)
       {
        mini = min(mini,abs(ans[i]-ans[i-1]));
       }
       return mini;
    }
};