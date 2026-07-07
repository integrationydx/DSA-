class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>f;
        for(int i=0;i<arr.size();i++)
        {
            f[arr[i]]++;
        }
        int maxi = INT_MIN;
        for(auto it:f)
        {
            if(it.first == it.second) 
            {
                 maxi = max(maxi,it.first);
            }
        }
        if(maxi == INT_MIN) return -1;
       return maxi;
        
    }

};