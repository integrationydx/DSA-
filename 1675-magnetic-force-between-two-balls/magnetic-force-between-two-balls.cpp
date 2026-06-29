class Solution {
public:
bool maxim(vector<int>& position, int dist, int m)
{
    int ball = 1;
    int last = position[0];

    for(int i = 1; i < position.size(); i++)
    {
        if(position[i] - last >= dist)
        {
            ball++;
            last = position[i];
        }

        if(ball >= m)
            return true;
    }

    return false;
}

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int ans = 0;
        int low = 1;
        int high = position[n-1] - position[0];
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(maxim(position,mid,m))
            {
                ans = mid;
                low = mid +1;
            }
            else{
                high = mid -1;
            }

        }
return ans;
    }
};