class Solution {
public:

    void fun(TreeNode* root, vector<vector<int>>& ds,
             vector<int>& ans)
    {
        if(root == NULL)
            return;

        ans.push_back(root->val);

        if(root->right == NULL && root->left == NULL)
        {
            ds.push_back(ans);
        }

        fun(root->left, ds, ans);
        fun(root->right, ds, ans);

        ans.pop_back();
    }

    int sumRootToLeaf(TreeNode* root)
    {
        vector<vector<int>> ds;
        vector<int> ans;

        fun(root, ds, ans);

        int total = 0;

        for(int i = 0; i < ds.size(); i++)
        {
            int num = 0;

            for(int j = 0; j < ds[i].size(); j++)
            {
                num = num * 2 + ds[i][j];
            }

            total += num;
        }

        return total;
    }
};