class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(n!=m) return -1;
         
         for(int i=0;i<n;i++)
         {
            if(s == goal) return true;
            s = s.substr(1) + s[0];
         }
         return false;

    }
};