class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
       if(next_permutation(s.begin(),s.end())) 
       {
        long long ans = stoll(s);
       
       if(ans <= INT_MAX) return ans;
       }

       return -1;
    }
};