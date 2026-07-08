class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if (i == 0) {
                    if (prefix[j] == k)
                        count++;
                }
                else {
                    if (prefix[j] - prefix[i - 1] == k)
                        count++;
                }

            }
        }

        return count;
    }
};