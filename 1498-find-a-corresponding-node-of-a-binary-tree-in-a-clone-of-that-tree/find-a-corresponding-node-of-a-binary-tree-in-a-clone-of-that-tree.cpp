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
TreeNode* fun(TreeNode * cloned,TreeNode * target)
{
    if(cloned == NULL) return NULL;
  if(cloned->val == target->val)
  {
    return cloned;
  }
    TreeNode * left = fun(cloned->left,target);
   TreeNode * right =  fun(cloned->right,target);

   if(left!=NULL) return left;
   return right;
   


}
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
     return fun(cloned,target);
    }
};