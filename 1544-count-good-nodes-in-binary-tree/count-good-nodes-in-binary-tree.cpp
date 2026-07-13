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

   int maxi = INT_MIN;
int fun(TreeNode* root,int maxi,int &count)
{
   if(root == NULL) return -1;
   if(root->val >= maxi) count++;
    maxi = max(maxi,root->val);
  fun(root->left,maxi,count);
  fun(root->right,maxi,count);
 

   return count;




}
    int goodNodes(TreeNode* root) {
        int count = 0;
        return fun(root,maxi,count);
    }
};