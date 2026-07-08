class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sumi = 0;
        int n = arr.size();
        vector<int>prefix(n);
        prefix[0] = arr[0];
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1] + arr[i];
        }
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i;j<arr.size();j++)
            {
                int x = j-i+1;
               if(x%2!=0) 
               {
                 if (i == 0)
    sumi += prefix[j];
else
    sumi += prefix[j] - prefix[i - 1];
               }
            }
        }
        return sumi;
    }
};