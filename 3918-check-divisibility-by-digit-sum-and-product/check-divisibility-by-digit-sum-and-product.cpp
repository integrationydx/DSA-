class Solution {
public:
    bool checkDivisibility(int n) {
        vector<int>f;
        int y = n;
        while(n>0)
        {
            f.push_back(n%10);
            n = n/10;
        }
        int sum = 0;
        int prod = 1;
        for(int i=0;i<f.size();i++)
        {
            sum+= f[i];
        }
        for(int i=0;i<f.size();i++)
        {
            prod = prod*f[i];
        }
        if(y%(sum+prod)==0) return true;
        return false;
    }
};