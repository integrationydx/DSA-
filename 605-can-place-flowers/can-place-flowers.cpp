class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int> f = flowerbed;
        int count = 0;
        if(f.size() == 1)
{
    if(f[0] == 0) count++;
}
        if(f.size() > 1 && f[0] == 0 && f[1] == 0)
        {
            f[0] = 1;
            count++;
        }
        for(int i=1;i<f.size()-1;i++)
        {
            if(f[i-1] == 0 && f[i+1] == 0 && f[i] ==0)
            {
                f[i] = 1;
                count++;
            }
            }
            int last = f.size()-1;
if(last > 0 && f[last] == 0 && f[last-1] == 0)
{
    f[last] = 1;
    count++;
}
          if(count >= n) return true;

           return false;

        }
       
    
};