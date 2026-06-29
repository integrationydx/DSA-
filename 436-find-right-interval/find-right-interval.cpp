class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int target = intervals[i][1];
            int mini = INT_MAX;
            int index = -1;

            for (int j = 0; j < n; j++) {
                if (intervals[j][0] >= target) {
                    if (intervals[j][0] < mini) {
                        mini = intervals[j][0];
                        index = j;
                    }
                }
            }

            ans.push_back(index);
        }

        return ans;
    }
};