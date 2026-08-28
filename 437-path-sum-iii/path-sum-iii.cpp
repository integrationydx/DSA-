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
int fun(TreeNode * root,int target,long long sum)
{
    if(root == NULL) return 0;
     sum+= root->val;
    int count = 0;
    if(sum == target) count++;
    int left = fun(root->left,target,sum);
    int right = fun(root->right,target,sum);
    return count+ left+ right;
}
    int pathSum(TreeNode* root, int target) {
      if(root == NULL) return 0;
      return fun(root,target,0) + pathSum(root->left,target) + pathSum(root->right,target);

    }
};