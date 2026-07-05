class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>f = heights;
        sort(f.begin(),f.end());
        int count = 0;
       for(int i=0;i<heights.size();i++)
       {
        if(heights[i]!= f[i]) count++;
       }
       return count;
    }
};