class Solution {
public:
    string reverseWords(string s) {
        string res1 = "";
        string res2 = "";

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (!res1.empty())
                {
                    reverse(res1.begin(), res1.end());

                    if (!res2.empty())
                        res2 += ' ';

                    res2 += res1;
                    res1.clear();
                }
            }
            else
            {
                res1 += s[i];
            }
        }

        if (!res1.empty())
        {
            reverse(res1.begin(), res1.end());

            if (!res2.empty())
                res2 += ' ';

            res2 += res1;
        }

        return res2;
    }
};