class Solution {
public:
bool help(string &s)
{
    int i = 0;
    int j = s.size()-1;
    while(i<j)
    {
        if(s[i] == s[j])
        {
            i++;
            j--;
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
int maxi = INT_MIN;
void fun(string res,string f,string &s,int i,int n)
{
    if(i == n)
    {
        if(help(res) == true && help(f) == true)
        {
            maxi = max(maxi, (int)(res.size() * f.size()));

        }
        return;
    }

    fun(res+s[i],f,s,i+1,n);
    fun(res,f+s[i],s,i+1,n);
    fun(res,f,s,i+1,n);

}

    int maxProduct(string s) {
        int n = s.size();
        string res = "";
        string f = "";
         fun(res,f,s,0,n);
         return maxi;
    }
};