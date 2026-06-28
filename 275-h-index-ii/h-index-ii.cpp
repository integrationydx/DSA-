class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        int low = 0;
        int high = n;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int count = 0;

            for (int i = 0; i < n; i++) {
                if (citations[i] >= mid) {
                    count++;
                }
            }

            if (count >= mid) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};