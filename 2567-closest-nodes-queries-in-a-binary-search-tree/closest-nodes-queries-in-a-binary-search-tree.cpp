class Solution {
public:
    vector<int> f;

    void fun(TreeNode* root)
    {
        if(root == NULL) return;

        fun(root->left);
        f.push_back(root->val);
        fun(root->right);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& nums)
    {
        fun(root);

        vector<vector<int>> ans;

        for(int i = 0; i < nums.size(); i++)
        {
            
            int low = 0;
            int high = f.size() - 1;
            int floor = -1;

            while(low <= high)
            {
                int mid = (low + high) / 2;

                if(f[mid] <= nums[i])
                {
                    floor = f[mid];
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

          
            low = 0;
            high = f.size() - 1;
            int ceil = -1;

            while(low <= high)
            {
                int mid = (low + high) / 2;

                if(f[mid] >= nums[i])
                {
                    ceil = f[mid];
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            
            ans.push_back({floor, ceil});
        }

        return ans;
    }
};