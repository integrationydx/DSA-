class Solution {
public:
    int reverse(int x) {
        vector<int> f;
        bool positive = true;

        long long n = x;   

        if (n < 0) {
            positive = false;
            n = -n;
        }

        while (n > 0) {
            f.push_back(n % 10);
            n /= 10;
        }

        long long num = 0;
        for (int digit : f) {
            num = num * 10 + digit;
        }

        if (!positive)
            num = -num;

        if (num > INT_MAX || num < INT_MIN)
            return 0;

        return (int)num;
    }
};