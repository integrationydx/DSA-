class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string res = a;
        int count = 1;

       
        while (res.size() < b.size()) {
            res += a;
            count++;
        }

        
        if (res.find(b) != string::npos)
            return count;

        res += a;
        count++;

        if (res.find(b) != string::npos)
            return count;

        return -1;
    }
};