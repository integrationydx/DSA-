class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
     vector<int>prefix(n);
     prefix[0] = nums[0];
     for(int i=1;i<nums.size();i++)
     {
       prefix[i] = prefix[i-1] + nums[i];
     }
     int x =  *min_element(prefix.begin(),prefix.end());
     if(x >=1) return 1;
    return 1-x;
    }
};