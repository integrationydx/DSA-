class Solution {
public:
void fun(int n,string &res)
{
    if(n == 1) return ;
    int count = 1;
    string temp = "";
    
    for(int i=0;i<res.size();i++)
    {
      if(i+1<res.size() && res[i]== res[i+1])
      {
        count++;
      }
      else{
        temp+= to_string(count);
        temp+= res[i];
        count = 1;

      }

    }
    res = temp;
    fun(n-1,res);

}
    string countAndSay(int n) {
        string res = "1";
        fun(n,res);
        return res;
    }
};