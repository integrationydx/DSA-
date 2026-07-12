class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ds;
        vector<int> ans1, ans2;

        // nums1 - nums2
        for (int i = 0; i < nums1.size(); i++) {
            bool found = false;
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                bool present = false;
                for (int k = 0; k < ans1.size(); k++) {
                    if (ans1[k] == nums1[i]) {
                        present = true;
                        break;
                    }
                }

                if (!present)
                    ans1.push_back(nums1[i]);
            }
        }

        // nums2 - nums1
        for (int i = 0; i < nums2.size(); i++) {
            bool found = false;
            for (int j = 0; j < nums1.size(); j++) {
                if (nums2[i] == nums1[j]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                bool present = false;
                for (int k = 0; k < ans2.size(); k++) {
                    if (ans2[k] == nums2[i]) {
                        present = true;
                        break;
                    }
                }

                if (!present)
                    ans2.push_back(nums2[i]);
            }
        }

        ds.push_back(ans1);
        ds.push_back(ans2);

        return ds;
    }
};