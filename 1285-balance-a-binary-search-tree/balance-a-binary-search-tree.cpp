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
TreeNode * solve(int left,int right)
{
  if(left>right) return NULL;

  int mid = (left + right)/2;
  TreeNode* root = new TreeNode (f[mid]);
  root->left = solve(left,mid-1);
  root->right = solve(mid+1,right);
  return root;



     

}
    TreeNode* balanceBST(TreeNode* root) {
        fun(root);
      return  solve(0,f.size()-1);
    }
};