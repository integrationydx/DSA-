class Solution {
public:
    void rotate(vector<int>& nums, int d) {
         vector<int>f;
        int n = nums.size();
        d = d % n;

        vector<int> temp(n);

        for(int i=0;i<nums.size();i++)
        {
          temp[(i+d)%n] = nums[i];
        }
        nums = temp;
    }
};