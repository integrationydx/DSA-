class Solution {
public:
    int minAddToMakeValid(string s) {
        int count1 = 0;
        int count2 = 0;
        int ans = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                count1++;
            }
            else{
                if(count1>0)   count1--;
                else{
                    ans++;
                }
             
            }
        }
      
        return(abs(count1+ans));
    }
};