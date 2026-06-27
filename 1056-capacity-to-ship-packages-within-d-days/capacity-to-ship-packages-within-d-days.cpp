class Solution {
public:

    int daysNeeded(vector<int>& weights, int capacity)
    {
        int load = 0;
        int count = 1;

        for(int i = 0; i < weights.size(); i++)
        {
            if(load + weights[i] <= capacity)
            {
                load += weights[i];
            }
            else
            {
                count++;
                load = weights[i];
            }
        }

        return count;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = 0;

        for(int i = 0; i < weights.size(); i++)
        {
            high += weights[i];
        }

        int ans = -1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(daysNeeded(weights, mid) <= days)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};