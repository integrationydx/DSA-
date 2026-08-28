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
TreeNode * fun(int low,vector<int> &nums,int high)
{
    if(low>high)
    {
        return NULL;
    }
    int maxi = low;
    for(int i=low;i<=high;i++)
    {
        if(nums[i]>nums[maxi])
        {
            maxi = i;
        }
    }
TreeNode * root = new TreeNode(nums[maxi]);
   root->left = fun(low,nums,maxi-1); // left recursion
    // right recursion // 
   root->right = fun(maxi+1,nums,high);
   return root;

}
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       int high = nums.size()-1;
       int low = 0;
     return  fun(low,nums,high);
    }
};