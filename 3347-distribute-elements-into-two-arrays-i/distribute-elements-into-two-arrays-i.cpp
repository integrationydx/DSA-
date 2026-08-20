class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>f;
        vector<int>temp;
        f.push_back(nums[0]);
        temp.push_back(nums[1]);

        int n = nums.size();
        for(int i=2;i<n;i++)
        {
            if(f.back()>temp.back()) f.push_back(nums[i]);
            else{
                temp.push_back(nums[i]);
            }
        }
        f.insert(f.end(),temp.begin(),temp.end());
        return f;
    }
};