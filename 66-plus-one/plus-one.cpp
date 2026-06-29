class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>f;
        int n =digits.size();

        if(n == 0)
        {
            f.push_back(1);
                            return f;

        }
        if(n == 1)
        {
            if(digits[0] == 9)
            {
                f.push_back(1);
                f.push_back(0);
                return f;
            }
        }
    
        for(int i=n-1;i>=0;i--)
        {
            if(digits[i] < 9)
            {
               digits[i]++;
               return digits;
            }
            else{
                digits[i] = 0;
                
            }
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};