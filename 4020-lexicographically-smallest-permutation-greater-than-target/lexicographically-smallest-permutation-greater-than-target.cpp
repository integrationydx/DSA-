class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        sort(s.begin(), s.end());

        int n = s.size();

        for (int i = n - 1; i >= 0; i--) {
            string prefix = target.substr(0, i);
            string remaining = s;

            bool possible = true;

            for (char c : prefix) {
                auto it = find(remaining.begin(), remaining.end(), c);

                if (it == remaining.end()) {
                    possible = false;
                    break;
                }

                remaining.erase(it);
            }

            if (!possible)
                continue;

            char best = '{';
            
            for (char c : remaining) {
                if (c > target[i]) {
                    best = min(best, c);
                }
            }

            if (best != '{') {
                string ans = prefix;
                ans += best;

                remaining.erase(
                    find(remaining.begin(), remaining.end(), best)
                );

                ans += remaining;

                return ans;
            }
        }

        return "";
    }
};