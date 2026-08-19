class Solution {
public:

    bool freeSeats(vector<int> seats, set<int>& reserved)
    {
        for(int seat : seats)
        {
            if(reserved.count(seat))
                return false;
        }

        return true;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, set<int>> reserved;

        for(auto seat : reservedSeats)
        {
            reserved[seat[0]].insert(seat[1]);
        }

        int ans = 2 * n;

        for(auto &row : reserved)
        {
            int r = row.first;

            bool left = freeSeats({2,3,4,5}, reserved[r]);
            bool middle = freeSeats({4,5,6,7}, reserved[r]);
            bool right = freeSeats({6,7,8,9}, reserved[r]);

            int families = 0;

            if(left)
                families++;

            if(right)
                families++;

            if(!left && !right && middle)
                families++;
            ans -= (2 - families);
        }

        return ans;
    }
};