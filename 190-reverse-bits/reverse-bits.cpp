class Solution {
public:
    int reverseBits(int n) {

        vector<int> f;


        for (int i = 0; i < 32; i++) {
            f.push_back(n & 1);
            n >>= 1;
        }

        long long num = 0;

        
        for (int i = 0; i < 32; i++) {
            num = num * 2 + f[i];
        }

        return (int)num;
    }
};