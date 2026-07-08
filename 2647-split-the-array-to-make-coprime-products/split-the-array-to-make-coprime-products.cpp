class Solution {
public:
    // Return all distinct prime factors of x
    vector<int> getPrimeFactors(int x) {
        vector<int> factors;

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                factors.push_back(i);
                while (x % i == 0)
                    x /= i;
            }
        }

        if (x > 1)
            factors.push_back(x);

        return factors;
    }

    int findValidSplit(vector<int>& nums) {
        int n = nums.size();

        // Stores the last index where each prime factor appears
        unordered_map<int, int> lastOccurrence;

        // Pass 1: Find the last occurrence of every prime factor
        for (int i = 0; i < n; i++) {
            vector<int> factors = getPrimeFactors(nums[i]);
            for (int p : factors)
                lastOccurrence[p] = i;
        }

        int rightMost = 0;

        // Pass 2: Scan from left to right
        for (int i = 0; i < n - 1; i++) {

            vector<int> factors = getPrimeFactors(nums[i]);

            // Extend the interval if any prime continues later
            for (int p : factors)
                rightMost = max(rightMost, lastOccurrence[p]);

            // If we've reached the end of all active intervals,
            // we can split here.
            if (i == rightMost)
                return i;
        }

        return -1;
    }
};