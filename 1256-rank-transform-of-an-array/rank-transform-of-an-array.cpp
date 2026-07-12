class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> f = arr;

        sort(f.begin(), f.end());

        unordered_map<int,int> g;

        int j = 1;          

        for(int i = 0; i < f.size(); i++)
        {
            if(g.find(f[i]) == g.end())
            {
                g[f[i]] = j;
                j++;
            }
        }

        vector<int> output;

        for(int i = 0; i < arr.size(); i++)
        {
            output.push_back(g[arr[i]]);
        }

        return output;
    }
};