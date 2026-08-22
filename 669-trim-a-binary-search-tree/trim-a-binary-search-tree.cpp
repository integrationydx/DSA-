class Solution {
public:

TreeNode* fun(TreeNode* root, int low, int high)
{
    if(root == NULL)
        return NULL;

    if(root->val < low)
        return fun(root->right, low, high);

    if(root->val > high)
        return fun(root->left, low, high);

    root->left = fun(root->left, low, high);
    root->right = fun(root->right, low, high);

    return root;
}

    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
      return fun(root,low,high);
    }
};