class Solution {
public:

    int maxi = 0;

    struct Info {
        int mini;
        int maxi;
        int sum;
        bool isBST;
    };

    Info fun(TreeNode* root)
    {
        if(root == NULL)
        {
            return {INT_MAX, INT_MIN, 0, true};
        }

        Info left = fun(root->left);
        Info right = fun(root->right);

        if(left.isBST &&
           right.isBST &&
           left.maxi < root->val &&
           root->val < right.mini)
        {
            int sum = left.sum + root->val + right.sum;

            maxi = max(maxi, sum);

            return {
                min(left.mini, root->val),
                max(right.maxi, root->val),
                sum,
                true
            };
        }

        return {
            INT_MIN,
            INT_MAX,
            0,
            false
        };
    }

    int maxSumBST(TreeNode* root)
    {
        fun(root);
        return maxi;
    }
};