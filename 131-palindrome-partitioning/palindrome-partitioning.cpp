class Solution {
public:
bool Pal(string &s,int left,int right)
{
    while(left<right)
    {
        if(s[left] == s[right])
        {
            left++;
            right--;
        }
        else{
            return false;
        }
    }
    return true;
}

void fun(int idx,vector<vector<string>>&ds,vector<string>&ans,string &s)
{
    int n = s.size();
    if(idx == n)
    { 
            ds.push_back(ans);
            return;
    
    }
    for(int i=idx;i<n;i++)
    {
      if(Pal(s,idx,i))
      {
         ans.push_back(s.substr(idx,i-idx+1));
        fun(i+1,ds,ans,s);
        ans.pop_back();
      }
    }
}

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ds;
        vector<string>ans;
        fun(0,ds,ans,s);
        return ds;
    }
};