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

void traverse(TreeNode* root)
{
    if(root == NULL) return;
    traverse(root->left);
    f.push_back(root->val);
    traverse(root->right);
}
 int fun(TreeNode* root)
    {
        if(root == NULL) return 0;

        int original = root->val;

        int left = fun(root->left);
        int right = fun(root->right);

        root->val = abs(left - right);

        return original + left + right;
    }
    int findTilt(TreeNode* root) {
       fun(root);
       traverse(root);
       int sum = 0;
       for(int i=0;i<f.size();i++)
       {
         sum+= f[i];
       }
       return sum;
   
    }
};