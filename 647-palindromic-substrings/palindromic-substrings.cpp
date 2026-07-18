class Solution {
public:
bool pal(string &res)
{
    int low = 0;
    int high = res.size() -1;
    while(low<=high)
    {
       if(res[low]!=res[high]) return false;
       else{
        low++;
        high--;
       }
    }
    return true;
}
    int countSubstrings(string s) {
        int n = s.size();
        string res = "";
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                res = s.substr(i,j-i+1);
                if(pal(res)) count++;
            }
        }
        return count;
    }
};