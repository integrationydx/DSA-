class Solution {
public:
    long long mini = LLONG_MAX;
    int first;

    void fun(TreeNode* root)
    {
        if(root == NULL)
            return;

        if(root->val > first)
        {
            mini = min(mini, (long long)root->val);
        }

        fun(root->left);
        fun(root->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        first = root->val;

        fun(root);

        if(mini == LLONG_MAX)
            return -1;

        return (int)mini;
    }
};