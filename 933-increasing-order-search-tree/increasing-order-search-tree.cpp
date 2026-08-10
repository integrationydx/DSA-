class Solution {
public:
    TreeNode* prev = NULL;
    TreeNode* newRoot = NULL;

    void fun(TreeNode* root)
    {
        if(root == NULL) return;

        fun(root->left);

        if(prev == NULL)
            newRoot = root;
        else
            prev->right = root;

        root->left = NULL;

        prev = root;

        fun(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        fun(root);
        return newRoot;
    }
};