class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int ans = 0;
        vector<int>f = nums;
        sort(f.begin(),f.end());
        for(int i=0;i<k;i++)
        {
            ans+= f.back();
            f.back()++;
        }
        return ans;
    }
};