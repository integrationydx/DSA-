class Solution {
public:
    int maxProduct(int n) {
        vector<int>ans;
        while(n>0)
        {
            ans.push_back(n%10);
            n = n/10;
        }
     
        reverse(ans.begin(),ans.end());
        sort(ans.begin(),ans.end());
           int y = ans.size();
        int x = ans[y-1]*ans[y-2];
        return x;
    }
};