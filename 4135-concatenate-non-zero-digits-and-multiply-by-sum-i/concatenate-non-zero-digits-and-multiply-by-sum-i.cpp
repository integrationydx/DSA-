class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int>f;
        while(n>0)
        {
            if(n%10!=0)
            {
             f.push_back(n%10);
            }

            n = n/10;
        }
        reverse(f.begin(),f.end());
        int sumi = 0;
        for(int i=0;i<f.size();i++)
        {
            sumi+= f[i];
        }
        long long num = 0;
        for(int i=0;i<f.size();i++)
        {
             num = num*10 + f[i];
        }
        return num*sumi;

    }
};