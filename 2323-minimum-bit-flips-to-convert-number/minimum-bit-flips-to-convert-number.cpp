class Solution {
public:
    int minBitFlips(int start, int goal) {
        vector<int>f;
        vector<int>g;
        while(start>0)
        {
            if(start%2 == 1)f.push_back(1);
            else{
                f.push_back(0);
            }
           start = start/2;
        }
        while(goal>0)
        {
            if(goal%2 == 1)g.push_back(1);
            else{
                g.push_back(0);
            }
            goal = goal/2;
        }
        while (f.size() < g.size())
    f.push_back(0);

while (g.size() < f.size())
    g.push_back(0);
        int count = 0;
        for(int i =0;i<f.size();i++)
        {
            if(f[i]!=g[i]) count++;
        }
        return count;
    }
};