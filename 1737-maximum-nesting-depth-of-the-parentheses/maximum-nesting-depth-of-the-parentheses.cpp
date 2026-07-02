class Solution {
public:
    int maxDepth(string s) {
        vector<int>f;
        int count1 =0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                count1++;
                f.push_back(count1);
            }
            if(s[i] == ')')
            {
                count1--;
            }
        }
        if(f.size() == 0) return 0;
        return *max_element(f.begin(),f.end());
    }
};