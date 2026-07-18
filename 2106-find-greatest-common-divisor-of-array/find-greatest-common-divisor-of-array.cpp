class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n1 = *max_element(nums.begin(),nums.end());
        int n2 = *min_element(nums.begin(),nums.end());
        int x = max(n1,n2);
        int maxi = INT_MIN;
        for(int i =1;i<=x;i++)
        {
            if(n1%i == 0 && n2%i== 0) 
            {
                maxi = max(maxi,i);
            }
        }
        return maxi;
    }
};