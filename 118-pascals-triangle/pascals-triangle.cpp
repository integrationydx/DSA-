class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        for(int i = 0; i < numRows; i++)
        {
            vector<int> temp;

            temp.push_back(1);

            if(i > 0)
            {
                vector<int> prev = ans[i - 1];

                for(int j = 0; j < prev.size() - 1; j++)
                {
                    temp.push_back(prev[j] + prev[j + 1]);
                }

                temp.push_back(1);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};