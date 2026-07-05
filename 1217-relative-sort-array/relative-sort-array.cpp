class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        vector<int> f;
        unordered_map<int, int> g;

        // Store frequencies of arr1
        for(int i = 0; i < arr1.size(); i++)
        {
            g[arr1[i]]++;
        }

        // Part 1: Add elements present in arr2
        for(int i = 0; i < arr2.size(); i++)
        {
            if(g.find(arr2[i]) != g.end())
            {
                int freq = g[arr2[i]];

                for(int j = 0; j < freq; j++)
                {
                    f.push_back(arr2[i]);
                }

                g.erase(arr2[i]);   // Remove from map
            }
        }

        // Part 2: Add remaining elements
        vector<int> temp;

        for(auto it : g)
        {
            for(int j = 0; j < it.second; j++)
            {
                temp.push_back(it.first);
            }
        }

        sort(temp.begin(), temp.end());

        for(int i = 0; i < temp.size(); i++)
        {
            f.push_back(temp[i]);
        }

        return f;
    }
};