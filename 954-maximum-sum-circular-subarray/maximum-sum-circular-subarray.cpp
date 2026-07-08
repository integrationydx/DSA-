class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int best_ending = nums[0];
int best_sum = nums[0];
int n = nums.size();

int worst_sum = nums[0];
int worst_ending = nums[0];

for (int i = 1; i < n; i++) {
    int val = nums[i] + worst_ending;

    if (nums[i] > val)
        worst_ending = val;
    else
        worst_ending = nums[i];

    if (worst_ending <worst_sum)
        worst_sum = worst_ending;
}


for (int i = 1; i < n; i++) {
    int val = nums[i] + best_ending;

    if (nums[i] > val)
        best_ending = nums[i];
    else
        best_ending = val;

    if (best_ending > best_sum)
        best_sum = best_ending;
}
int sumi = 0;
for(int i=0;i<nums.size();i++)
{
    sumi+= nums[i];
}
if(best_sum<0) return best_sum;

return max(best_sum,sumi -worst_sum);
    }
};