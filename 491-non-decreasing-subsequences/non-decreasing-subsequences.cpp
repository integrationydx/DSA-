class Solution {
public:
    void fun(vector<int>& nums, vector<int>& ans,
             set<vector<int>>& st, int i)
    {
        if(i == nums.size())
        {
            if(ans.size() >= 2)
                st.insert(ans);

            return;
        }

        if(ans.empty() || nums[i] >= ans.back())
        {
            ans.push_back(nums[i]);
            fun(nums, ans, st, i + 1);
            ans.pop_back();
        }

        fun(nums, ans, st, i + 1);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        vector<int> ans;
        set<vector<int>> st;

        fun(nums, ans, st, 0);

        vector<vector<int>> ds(st.begin(), st.end());

        return ds;
    }
};