class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int>f;
        for(int i=0;i<nums.size();i++)
        {
            f[nums[i]]++;
        }
        int sum = 0;
int n = nums.size();
for(int i = 0; i < n; i++)
{
    if(i == 0 || nums[i] == nums[i-1] + 1)
        sum += nums[i];
    else
        break;
}

while(f.find(sum) != f.end())
{
    sum++;
}

return sum;
    }
};