class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();

        if(k == 0)
        {
            return vector<int>(n, 0);
        }

        vector<int> f;
        int sum = 0;

        if(k > 0)
        {
            int low = 1;
            int high = k;

            for(int i = low; i <= high; i++)
            {
                sum += code[i];
            }

            f.push_back(sum);

            for(int i = 1; i < n; i++)
            {
                sum = sum
                    - code[low % n]
                    + code[(high + 1) % n];

                low++;
                high++;

                f.push_back(sum);
            }
        }
        else
        {
            int K = abs(k);

            int low = n - K;
            int high = n - 1;

            for(int i = low; i <= high; i++)
            {
                sum += code[i];
            }

            f.push_back(sum);

            for(int i = 1; i < n; i++)
            {
                sum = sum
                    - code[low % n]
                    + code[(high + 1) % n];

                low++;
                high++;

                f.push_back(sum);
            }
        }

        return f;
    }
};