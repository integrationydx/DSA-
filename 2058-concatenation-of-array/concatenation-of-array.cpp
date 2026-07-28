class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans = nums;
        vector<int>res = nums;
        ans.insert(ans.end(),res.begin(),res.end());
        return ans;
    }
};